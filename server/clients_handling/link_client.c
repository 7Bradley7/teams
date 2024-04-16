/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "server.h"

static void link_client_fd(myteams_t *m, int fd)
{
    if (fd > m->s.mfd) {
        m->s.mfd = fd;
    }
}

void link_client(myteams_t *m)
{
    FD_ZERO(&m->s.read_fds);
    FD_SET(m->s.sk.fd, &m->s.read_fds);
    m->s.mfd = m->s.sk.fd;
    for (int i = 0; i != MAX_CLIENTS; i++) {
        if (m->c[i].sk.fd != EMPTY_SOCKET) {
            FD_SET(m->c[i].sk.fd, &m->s.read_fds);
            link_client_fd(m, m->c[i].sk.fd);
        }
    }
}
