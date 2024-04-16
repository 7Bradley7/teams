/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include "client.h"

void users_message(myteams_t *m, char **params)
{
    header_t request;

    memset(&request, 0, sizeof(request));
    request.command_code = USERS_CODE;
    memcpy(request.user_uuid, m->c.u.uuid, sizeof(request.user_uuid));
    send_packet(m->c.sk.fd, &request);
}
