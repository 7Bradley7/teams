/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "client.h"

void logout_message(myteams_t *m, char **wa)
{
    header_t request;

    memset(&request, 0, sizeof(request));
    request.command_code = LOGOUT_CODE;
    memcpy(request.user_uuid, m->c.u.uuid, sizeof(request.user_uuid));
    send_packet(m->c.sk.fd, &request);
}
