/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** utils
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "utils.h"

char *cpy_fixed(char const *str, size_t const len)
{
    char *new_str = calloc(len + 1, sizeof(char));

    if (new_str == NULL)
        return NULL;
    strncpy(new_str, str, len);
    return new_str;
}

bool uuid_eq(uuID_t const a, uuID_t const b)
{
    return strncmp(a, b, MAX_UUID_LENGTH) == 0;
}

bool username_eq(username_t const a, username_t const b)
{
    return strncmp(a, b, MAX_USERNAME_LENGTH) == 0;
}
