/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

static void quit_client(client_t *client)
{
    if (close(client->sk.fd) == ERROR) {
        printf("Closing failed\n");
    }
    client->sk.fd = EMPTY_SOCKET;
    client->u.is_logged = false;
    memset(client->u.username, 0, sizeof(client->u.username));
    memset(client->u.uuid, 0, sizeof(client->u.uuid));
}

static void read_message_client(client_t *client)
{
    int rd = read(client->sk.fd, client->h, sizeof(header_t));

    if (rd <= 0) {
        quit_client(client);
        return;
    }
    if (rd < sizeof(header_t)) {
        printf("Missing information for the server\n");
        return;
    }
    client->h = realloc(client->h, sizeof(*client->h) + client->h->body_size);
    read(client->sk.fd, client->h + 1, client->h->body_size);
}

void message_client(myteams_t *m)
{
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (FD_ISSET(m->c[i].sk.fd, &m->s.read_fds) &&
        m->c[i].sk.fd != EMPTY_SOCKET) {
            read_message_client(&m->c[i]);
            handle_message(m, i);
        }
    }
}
