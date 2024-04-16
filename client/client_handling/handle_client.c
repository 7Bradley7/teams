/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"

static void quit_client(client_t *client)
{
    if (close(client->sk.fd) == ERROR) {
        printf("Closing failed\n");
    }
    client->sk.fd = EMPTY_SOCKET;
    client->u.is_logged = false;
}

static void read_message_client(client_t *client)
{
    int rd = read(client->sk.fd, client->h, sizeof(header_t));

    if (rd <= 0) {
        quit_client(client);
        return;
    }
    if (rd < sizeof(header_t)) {
        printf("Missing header\n");
        return;
    }
    client->h = realloc(client->h, sizeof(*client->h) + client->h->body_size);
    read(client->sk.fd, client->h + 1, client->h->body_size);
}

static void read_standard_input(myteams_t *m)
{
    char *message = calloc(MAX_BODY_LENGTH, sizeof(char));
    size_t len = MAX_BODY_LENGTH;
    int read = getline(&message, &len, stdin);

    if (read == ERROR) {
        m->m.message = NULL;
    }
    m->m.message = strdup(message);
    for (int i = 0; m->m.message[i]; i++) {
        if (m->m.message[i] == '\n') {
            m->m.message[i] = '\0';
        }
    }
    free(message);
}

void handle_client(myteams_t *m)
{
    if (FD_ISSET(m->s.sk.fd, &m->s.read_fds)) {
        read_message_client(&m->c);
        handle_command(m);
    } else if (FD_ISSET(STANDARD_INPUT, &m->s.read_fds)) {
        read_standard_input(m);
        handle_message(m);
    }
}
