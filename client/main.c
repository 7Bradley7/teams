/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "client.h"
#include "macro.h"

static void ip_handling(char *ip, myteams_t *m)
{
    for (int i = 0; ip[i]; i++) {
        if (!isdigit(ip[i]) && ip[i] != '.') {
            exit(FAIL);
        }
    }
    m->s.ip = ip;
}

static void port_handling(int port, myteams_t *m)
{
    if (port > MAX_PORT || port < MIN_PORT) {
        exit(FAIL);
    }
    m->s.port = port;
}

static void error_handling(int ac, char **av, myteams_t *m)
{
    if (ac == 1) {
        if (!strcmp(av[0], "-help")) {
            printf("USAGE: ./myteams_cli ip port\n\t"\
            "ip\tis the server ip address on which the server socket listens"\
            "\n\tport\tis "\
            "the port number on which the server socket listens\n");
            exit(SUCCESS);
        }
        exit(FAIL);
    }
    if (ac != 2) {
        exit(FAIL);
    }
    port_handling(atoi(av[1]), m);
    ip_handling(av[1], m);
}

int main(int ac, char **av)
{
    myteams_t m;

    error_handling(ac - 1, av + 1, &m);
    init_server(&m);
    init_client(&m);
    client_loop(&m);
}
