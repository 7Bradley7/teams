/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "server.h"

static int find_client_id(myteams_t *m)
{
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (m->c[i].sk.fd == EMPTY_SOCKET) {
            return (i);
        }
    }
    printf("Number of connection is limited\n");
    return (EMPTY_SOCKET);
}

void connect_client(myteams_t *m)
{
    int id = find_client_id(m);
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);

    if (id == EMPTY_SOCKET) {
        return;
    }
    m->c[id].sk.fd = accept(m->s.sk.fd
    , (struct sockaddr *)&addr, &addr_len);
    if (m->c[id].sk.fd == EMPTY_SOCKET) {
        printf("accept\n");
        return;
    }
    m->c[id].sk.addr_in = addr;
}
