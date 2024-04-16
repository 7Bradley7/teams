/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "client.h"

static void check_socket(myteams_t *m)
{
    if (m->s.sk.fd == ERROR) {
        close_server(m, "socket", FAIL);
    }
    m->c.sk.fd = m->s.sk.fd;
}

void init_server(myteams_t *m)
{
    m->s.sk.fd = socket(AF_INET, SOCK_STREAM, 0);
    m->s.sk.addr_in.sin_family = AF_INET;
    m->s.sk.addr_in.sin_addr.s_addr = INADDR_ANY;
    m->s.sk.addr_in.sin_port = htons(m->s.port);
    inet_pton(AF_INET, m->s.ip, &m->s.sk.addr_in.sin_addr.s_addr);
    m->s.mfd = m->s.sk.fd;
    check_socket(m);
}
