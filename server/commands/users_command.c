/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "users_req.h"

void users_command(myteams_t *m, client_t *c)
{
    users_response_t u;

    memset(&u, 0, sizeof(users_response_t));
    u.header.body_size = sizeof(u.body);
    u.header.command_code = USERS_CODE;
    memcpy(u.header.user_uuid, c->u.uuid, sizeof(u.header.user_uuid));
    for (size_t i = 0; i < MAX_CLIENTS; ++i) {
        if (strlen(m->c[i].u.username) > 0) {
            memcpy(&u.body.username, m->c[i].u.username,
                sizeof(u.body.username));
            memcpy(&u.body.uuid, m->c[i].u.uuid,
                sizeof(u.body.uuid));
            u.body.is_logged = m->c[i].u.is_logged;
            memcpy(&u.header.user_uuid, m->c[i].u.uuid, MAX_UUID_LENGTH);
            send_normal_by_protocol(c, (header_t *)&u);
            return;
        }
    }
}
