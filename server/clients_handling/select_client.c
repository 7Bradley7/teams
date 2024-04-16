/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "server.h"

void select_client(myteams_t *m)
{
    if (select(m->s.mfd + 1, &m->s.read_fds,
    WRITEFDS, EXPECTFDS, TIMEOUT) == ERROR) {
        close_clients(m);
        close_server(m, "select", FAIL);
    }
}
