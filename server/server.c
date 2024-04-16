/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static void sig_handler(int)
{
    exit(SUCCESS);
}

void server_loop(myteams_t *m)
{
    signal(SIGINT, sig_handler);
    while (true) {
        link_client(m);
        select_client(m);
        if (FD_ISSET(m->s.sk.fd, &m->s.read_fds))
            connect_client(m);
        message_client(m);
    }
    close_clients(m);
    close_server(m, NULL, SUCCESS);
}
