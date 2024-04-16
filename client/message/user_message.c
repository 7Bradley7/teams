/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "client.h"
#include "user_req.h"
#include "string.h"

void user_message(myteams_t *m, char **params)
{
    user_request_t request;
    int const argc = get_nbr_wa(params);

    if (argc == 0) {
        printf("Not enough arguments.\n");
        return;
    } else if (argc > 1)
        printf("Too many arguments, %s and the next ones will be ignored.\n",
        params[1]);
    init_packet((header_t *)&request, sizeof(request.body)
    , m->c.u.uuid, USER_CODE);
    memcpy(request.body.uuid, params[0], MIN(sizeof(request.header.user_uuid)
    , strlen(params[0])));
    send_packet(m->c.sk.fd, (header_t *)&request);
}
