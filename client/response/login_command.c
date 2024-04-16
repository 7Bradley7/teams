/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include <stdlib.h>
#include "client.h"
#include "utils.h"

static char *cpy(char const *str, size_t const max_len)
{
    size_t const len = strnlen(str, max_len);
    char *nuuid = malloc(sizeof(char) * (len + 1));

    memcpy(nuuid, str, len);
    nuuid[len] = '\0';
    return nuuid;
}

void login_command(myteams_t *m)
{
    login_response_t *response = (login_response_t *)m->c.h;

    if (response->header.error_code == USER_ALREADY_LOGGED_IN) {
        client_error_already_exist();
        return;
    } else if (response->header.error_code != NO_ERROR) {
        printf("login response: %s\n"
        , get_err_msg(response->header.error_code));
    }
    memcpy(m->c.u.username, response->body.username, sizeof(m->c.u.username));
    memcpy(m->c.u.uuid, response->body.uuid, sizeof(m->c.u.uuid));
    m->c.u.is_logged = true;
    client_event_logged_in(response->body.uuid, response->body.username);
}
