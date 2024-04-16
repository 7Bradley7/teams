/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "client.h"

void send_message(myteams_t *m, char **params)
{
    if (m->c.u.is_logged != true) {
        client_error_unauthorized();
        return;
    }
    if (get_nbr_wa(params) != 1) {
        printf("Wrong Params");
        return;
    }
}
