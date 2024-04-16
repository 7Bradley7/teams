/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

static void init_clients_user(myteams_t *m)
{
    memset(m->c, 0, sizeof(*m->c) * MAX_CLIENTS);
    for (int i = 0; i != MAX_CLIENTS; i++) {
        m->c[i].u.is_logged = false;
        m->c[i].u.password = "";
        m->c[i].sk.fd = -1;
    }
}

static void init_clients_socket(myteams_t *m)
{
    for (int i = 0; i != MAX_CLIENTS; i++) {
        m->c[i].sk.fd = EMPTY_SOCKET;
    }
}

void init_clients(myteams_t *m)
{
    m->c = malloc(sizeof(client_t) * MAX_CLIENTS);
    if (m->c == NULL) {
        close_server(m, "malloc", FAIL);
    }
    init_clients_socket(m);
    init_clients_user(m);
    m->c->h = calloc(1, sizeof(header_t));
}
