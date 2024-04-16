/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include "client.h"

void login_message(myteams_t *m, char **wa)
{
    login_t request;
    char *username;

    if (m->c.u.is_logged == true) {
        printf("Already logged in.\n");
        return;
    }
    if (get_nbr_wa(wa) != 1) {
        printf("Invalid username.\n");
        return;
    }
    memset(&request, 0, sizeof(login_t));
    request.h.command_code = LOGIN_CODE;
    request.h.body_size = sizeof(login_body_t);
    username = cpy_fixed(wa[0], sizeof(request.body.username));
    memcpy(request.body.username, username, sizeof(request.body.username));
    free(username);
    send_normal_by_protocol(&m->c, (header_t *)&request);
}
