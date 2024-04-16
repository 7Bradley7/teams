/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdio.h>
#include <stdlib.h>
#include "client.h"

static void sig_handler(int)
{
    exit(0);
}

static void connect_to_server(myteams_t *m)
{
    if (connect(m->s.sk.fd
    , (struct sockaddr*)&m->s.sk.addr_in
    , sizeof(m->s.sk.addr_in)) == ERROR) {
        close_client(&m->c);
        close_server(m, "connect", FAIL);
    }
}

void client_loop(myteams_t *m)
{
    connect_to_server(m);
    signal(SIGINT, sig_handler);
    while (true) {
        FD_ZERO(&m->s.read_fds);
        FD_SET(m->s.sk.fd, &m->s.read_fds);
        FD_SET(STANDARD_INPUT, &m->s.read_fds);
        if (select(m->s.mfd + 1, &m->s.read_fds,
        WRITEFDS, EXPECTFDS, TIMEOUT) == ERROR) {
            close_client(&m->c);
            close_server(m, "select", FAIL);
        }
        handle_client(m);
    }
    close_client(&m->c);
    close_server(m, NULL, SUCCESS);
}
