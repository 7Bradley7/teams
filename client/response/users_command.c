/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "client.h"
#include "users_req.h"

void users_command(myteams_t *m)
{
    users_response_t *u = (users_response_t *)m->c.h;

    client_print_users(u->body.uuid, u->body.username, u->body.is_logged);
}
