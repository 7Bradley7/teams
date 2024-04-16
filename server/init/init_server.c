/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "server.h"

static void check_socket(myteams_t *m)
{
    if (m->s.sk.fd == ERROR) {
        close_server(m, "socket", FAIL);
    }
    if (bind(m->s.sk.fd, (struct sockaddr *)&m->s.sk.addr_in
        , sizeof(m->s.sk.addr_in)) == ERROR) {
        close_server(m, "Binding failed", FAIL);
    }
    if (listen(m->s.sk.fd, MAX_CLIENTS) == ERROR) {
        close_server(m, "Listening failed", FAIL);
    }
    mkdir(PATH_LOG, 0777);
}

void init_server(myteams_t *m)
{
    m->s.sk.fd = socket(AF_INET, SOCK_STREAM, 0);
    m->s.sk.addr_in.sin_family = AF_INET;
    m->s.sk.addr_in.sin_addr.s_addr = INADDR_ANY;
    m->s.sk.addr_in.sin_port = htons(m->s.port);
    m->s.mfd = EMPTY_SOCKET;
    check_socket(m);
}
