/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

void assign_code(header_t *h, u_int8_t command_code, u_int8_t error_code)
{
    h->command_code = command_code;
    h->error_code = error_code;
}

void send_error_by_protocol(client_t *c, u_int8_t c_code, u_int8_t e_code)
{
    memcpy(c->h->user_uuid, c->u.uuid, MAX_UUID_LENGTH);
    assign_code(c->h, c_code, e_code);
    c->h->body_size = 0;
    if (c->u.is_logged == true && c_code != LOGIN_CODE) {
        strcpy(c->h->user_uuid, c->u.uuid);
    }
    if (send(c->sk.fd, &c->h, HEADER_SIZE, 0) == ERROR) {
        printf("===== Send Error failed =====\n");
    }
}

void send_normal_by_protocol(client_t *c, header_t *packet)
{
    if (c->u.is_logged == true) {
        strcpy(c->h->user_uuid, c->u.uuid);
    }
    send_packet(c->sk.fd, packet);
}
