/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include "server.h"

static void create_user(client_t *c, char *username)
{
    uuid_t uuid;
    char *uuid_str = malloc(MAX_UUID_LENGTH);

    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);
    memset(c->u.username, 0, sizeof(c->u.username));
    memcpy(c->u.username, username
    , MIN(sizeof(c->u.username), strlen(username)));
    memset(c->u.uuid, 0, sizeof(c->u.uuid));
    memcpy(c->u.uuid, uuid_str, MIN(sizeof(c->u.uuid), strlen(uuid_str)));
    write_in_logins_log(c->u.username, c->u.uuid);
    server_event_user_created(c->u.uuid, c->u.username);
}

static void user_check(client_t *c, char *username)
{
    char **logs = parse_logins_by_username(username);
    char *usr;
    char *uuid;

    if (logs == NULL) {
        create_user(c, username);
        return;
    }
    usr = cpy_fixed(logs[0], sizeof(c->u.username));
    uuid = cpy_fixed(logs[1], sizeof(c->u.uuid));
    memcpy(c->u.username, usr, sizeof(c->u.username));
    memcpy(c->u.uuid, uuid, sizeof(c->u.uuid));
    free(usr);
    free(uuid);
}

static int check_user_already_logged_in(myteams_t *m, char *username)
{
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (m->c[i].u.is_logged == true
        && strcmp(m->c[i].u.username, username) == SUCCESS) {
            return (FAIL);
        }
    }
    return (SUCCESS);
}

static void login_user(client_t *c, login_t *l)
{
    server_event_user_logged_in(c->u.uuid);
    memcpy(l->body.username, c->u.username, strlen(c->u.username));
    memcpy(l->body.uuid, c->u.uuid, MAX_UUID_LENGTH);
    c->u.is_logged = true;
}

static void send_error(client_t *c, uint8_t com, uint8_t err)
{
    header_t response;

    memset(&response, 0, sizeof(response));
    response.command_code = com;
    response.error_code = err;
    response.body_size = 0;
    if (send(c->sk.fd, &response, sizeof(response), 0) == ERROR) {
        printf("===== Send Error failed =====\n");
    }
}

static void send_success(client_t *c, uint8_t const com, char const *uuid)
{
    login_response_t response;

    memset(&response, 0, sizeof(response));
    response.header.command_code = com;
    response.header.body_size = sizeof(response.body);
    memcpy(&response.body.uuid, uuid, MAX_UUID_LENGTH);
    memcpy(&response.body.username, c->u.username, MAX_USERNAME_LENGTH);
    if (send(c->sk.fd, &response, sizeof(response), 0) == ERROR) {
        printf("===== Send Normal failed =====\n");
    }
}

void login_command(myteams_t *m, client_t *c)
{
    char *username = calloc(MAX_USERNAME_LENGTH, sizeof(char));
    int len;

    if (check_user_already_logged_in(m
        , ((login_t *)c->h)->body.username) == FAIL) {
        send_error(c, LOGIN_CODE, USER_ALREADY_LOGGED_IN);
    } else {
        create_logs();
        user_check(c, ((login_t *)c->h)->body.username);
        login_user(c, ((login_t *)c->h));
        send_success(c, LOGIN_CODE, c->u.uuid);
    }
}
