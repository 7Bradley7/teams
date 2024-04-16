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

static const char *commands[] = {
    "/help",
    "/login",
    "/logout",
    "/users",
    "/user",
    "/send",
    "/messages",
    "/subscribe",
    "/subscribed",
    "/unsubscribe",
    "/use",
    "/create",
    "/list",
    "/info"
};

static void (*ptr[])(myteams_t *, char **) = {
    help_message,
    login_message,
    logout_message,
    users_message,
    user_message,
    send_message,
    messages_message,
    subscribe_message,
    subscribed_message,
    unsubscribe_message,
    use_message,
    create_message,
    list_message,
    info_message
};

static int command_index(char *command)
{
    if (command == NULL) {
        return (ERROR);
    }
    for (int i = 0; commands[i]; i++) {
        if (!strcmp(command, commands[i])) {
            return (i);
        }
    }
    return (ERROR);
}

void handle_message(myteams_t *m)
{
    char **wa;
    int index = ERROR;

    if (m->m.message == NULL) {
        return;
    }
    wa = strtwa(m->m.message, "  \"\t\n\r");
    if (wa != NULL) {
        index = command_index(wa[0]);
        if (index != ERROR) {
            ptr[index](m, wa + 1);
        }
    }
}
