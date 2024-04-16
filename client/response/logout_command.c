/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "client.h"

void logout_command(myteams_t *m)
{
    header_t *hd = m->c.h;

    if (hd->error_code == NO_ERROR) {
        client_event_logged_out(m->c.u.uuid, m->c.u.username);
        memset(m->c.u.username, 0, sizeof(m->c.u.username));
        memset(m->c.u.uuid, 0, sizeof(m->c.u.uuid));
        m->c.u.is_logged = false;
    }
}
