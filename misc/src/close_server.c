/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void close_clients_till_index(myteams_t *m, int index)
{
    for (int i = 0; i != index; i++) {
        if (m->c[i].sk.fd != EMPTY_SOCKET) {
            close(m->c->sk.fd);
        }
    }
    free(m->c);
}

void close_client(client_t *c)
{
    close(c->sk.fd);
}

void close_clients(myteams_t *m)
{
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (m->c[i].sk.fd != EMPTY_SOCKET) {
            close(m->c->sk.fd);
        }
        free(m->c[i].u.username);
        free(m->c[i].u.uuid);
    }
    free(m->c);
}

void close_server(myteams_t *m, char *error_str, int exit_code)
{
    if (error_str != NULL) {
        printf("%s\n", error_str);
    }
    close(m->s.sk.fd);
    exit(exit_code);
}
