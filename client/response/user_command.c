/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include "client.h"
#include "user_req.h"

void user_command(myteams_t *m)
{
    user_response_t *response = (user_response_t *)m->c.h;

    if (response->header.error_code != NO_ERROR) {
        printf("%s\n", get_err_msg(response->header.error_code));
    } else {
        client_print_user(response->body.uuid
        , response->body.username, response->body.status);
    }
}
