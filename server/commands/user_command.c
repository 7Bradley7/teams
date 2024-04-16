/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "user_req.h"

static void send_error(int fd, uuID_t const user_uuid, uint8_t err)
{
    header_t response;

    memset(&response, 0, sizeof(response));
    response.command_code = USER_CODE;
    response.error_code = err;
    send_packet(fd, &response);
}

static void send_response(client_t const *c, uuID_t const uuid,
    username_t const name, uint8_t status)
{
    user_response_t response;

    memset(&response, 0, sizeof(response));
    response.header.command_code = USER_CODE;
    response.header.body_size = sizeof(response.body);
    memcpy(response.header.user_uuid, c->u.uuid,
        sizeof(response.header.user_uuid));
    memcpy(response.body.uuid, uuid, sizeof(response.body.uuid));
    memcpy(response.body.username, name, sizeof(response.body.username));
    response.body.status = status;
    send_packet(c->u.uuid, (header_t *)&response);
}

void user_command(myteams_t *m, client_t *c)
{
    user_request_t *request = (user_request_t *)c->h;

    for (size_t i = 0; i < MAX_CLIENTS; ++i) {
        printf("%.37s - %.37s\n", request->body.uuid, m->c[i].u.uuid);
        if (uuid_eq(request->body.uuid, m->c[i].u.uuid)) {
            send_response(c, m->c[i].u.uuid,
                m->c[i].u.username, m->c[i].u.is_logged);
            return;
        }
    }
    send_error(c->sk.fd, c->u.uuid, REQUESTED_USER_NOT_FOUND);
}
