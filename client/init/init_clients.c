/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

static void init_client_message(myteams_t *m)
{
    m->m.len = 0;
    m->m.message = calloc(MAX_BODY_LENGTH, sizeof(char));
    if (m->m.message == NULL) {
        close_client(&m->c);
        close_server(m, "malloc", FAIL);
    }
}

static void init_client_user(myteams_t *m)
{
    m->c.u.is_logged = false;
    m->c.u.password = "";
    memset(m->c.u.username, 0, sizeof(m->c.u.username));
    memset(m->c.u.uuid, 0, sizeof(m->c.u.uuid));
}

void init_client(myteams_t *m)
{
    init_client_user(m);
    init_client_message(m);
    m->c.h = calloc(1, sizeof(header_t));
}
