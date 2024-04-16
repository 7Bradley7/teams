/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "server.h"

void logout_command(myteams_t *m, client_t *c)
{
    header_t response;

    memcpy(&response, c->h, sizeof(response));
    response.command_code = LOGOUT_CODE;
    memcpy(response.user_uuid, c->u.uuid, sizeof(response.user_uuid));
    server_event_user_logged_out(c->u.uuid);
    send_packet(c->sk.fd, &response);
}
