/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include "macro.h"

char **strtwa(char *str, char *token)
{
    int i = 0;
    char *tok = strtok(str, token);
    char **wa = malloc(sizeof(char *));

    if (str == NULL || wa == NULL || tok == NULL) {
        return (NULL);
    }
    for (; tok != NULL; i++) {
        wa[i] = strdup(tok);
        wa = realloc(wa, (sizeof(char *) * (i + 2)));
        tok = strtok(NULL, token);
    }
    wa[i] = tok;
    free(tok);
    return (wa);
}

int get_nbr_wa(char **wa)
{
    int i = 0;

    if (wa == NULL) {
        return (0);
    }
    for (; wa[i]; i++);
    return (i);
}

char *watstr(char **wa)
{
    char *params = calloc((MAX_BODY_LENGTH * 2), sizeof(char));
    int i = 0;

    if (wa == NULL && wa[0] == NULL) {
        return (NULL);
    }
    for (; wa[i] != NULL; i++) {
        strcat(params, wa[i]);
        strcat(params, " ");
    }
    if (strlen(params) == 0) {
        return (NULL);
    }
    params[strlen(params) - 1] = '\0';
    return (params);
}
