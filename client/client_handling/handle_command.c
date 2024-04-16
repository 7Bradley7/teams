/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"

static void (*ptr[])(myteams_t *) = {
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

void handle_command(myteams_t *m)
{
    int index = m->c.h->command_code;

    if (index > 13) {
        printf("Unknown Command, ignoring message\n");
        return;
    }
    ptr[index](m);
}
