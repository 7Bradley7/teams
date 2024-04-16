/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** print_utils
*/

#include <stdlib.h>
#include "print_utils.h"

static char *const cmd_names[] = {
    "HELP",
    "LOGIN",
    "LOGOUT",
    "USERS",
    "USER",
    "SEND",
    "MESSAGES",
    "SUBSCRIBE",
    "SUBSCRIBED",
    "UNSUBSCRIBE",
    "USE",
    "CREATE",
    "LIST",
    "INFO",
    "READY_TO_DISCONNECT",
    NULL
};

static char *const err_names[] = {
    "NO_ERROR",
    "USER_ALREADY_LOGGED_IN",
    "TOO_MUCH_PARAMS",
    "MISSING_PARAMS",
    "NOT_LOGGED_IN",
    "UNCOHERENT_UUID",
    "INVALID_PARAMS",
    "REQUESTED_USER_NOT_FOUND",
    "UNKNOWN",
    NULL
};

char const *get_cmd_name(uint8_t cmd)
{
    static char const *const def = "Unknown";
    uint8_t i = 0;

    for (; i != cmd && cmd_names[i] != NULL; ++i);
    return cmd_names[i] != NULL ? cmd_names[i] : def;
}

char const *get_err_msg(uint8_t cmd)
{
    static char const *const def = "Unknown error";
    uint8_t i = 0;

    for (; i != cmd && err_names[i] != NULL; ++i);
    return err_names[i] != NULL ? err_names[i] : def;
}
