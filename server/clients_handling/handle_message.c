/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

void (*ptr[])(myteams_t *, client_t *) = {
    help_command,
    login_command,
    logout_command,
    users_command,
    user_command,
    send_command,
    messages_command,
    subscribe_command,
    subscribed_command,
    unsubscribe_command,
    use_command,
    create_command,
    list_command,
    info_command
};

void handle_message(myteams_t *m, int id)
{
    char **wa;
    int index = m->c[id].h->command_code;

    if (m->c[id].sk.fd == ERROR) {
        return;
    }
    if (index > 13) {
        printf("Unknown Command, ignoring message\n");
        return;
    }
    ptr[index](m, &m->c[id]);
}
