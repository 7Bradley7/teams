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

static void port_handling(int port, myteams_t *m)
{
    if (port > MAX_PORT || port < MIN_PORT) {
        printf("Invalid port\n");
        exit(FAIL);
    }
    m->s.port = port;
}

static void error_handling(int ac, char **av, myteams_t *m)
{
    if (ac == 1) {
        if (!strcmp(av[0], "-help")) {
            printf("USAGE: ./myteams_terver port\n\n\t"
            "port\tis the port number on which the server socket listens.\n");
            exit(SUCCESS);
        }
        port_handling(atoi(av[0]), m);
        return;
    }
    printf("Invalid args\n");
    exit(FAIL);
}

int main(int ac, char **av)
{
    myteams_t m;

    error_handling(ac - 1, av + 1, &m);
    init_server(&m);
    init_clients(&m);
    server_loop(&m);
    free(m.c->h);
}
