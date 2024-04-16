/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** packet_utils
*/

#include <errno.h>
#include <string.h>
#include "utils.h"
#include "packet_utils.h"

bool send_packet(int fd, header_t const *packet)
{
    if (send(fd, packet, sizeof(header_t) + packet->body_size, 0)
        < get_packet_size(packet)) {
        printf("%s: %s %d\n", get_cmd_name(packet->command_code),
            strerror(errno), fd);
        return false;
    }
    return true;
}

void init_packet(header_t *header, uint16_t body_size, uuID_t const uuid,
    u_int8_t cmd)
{
    memset(header, 0, sizeof(header_t) + body_size);
    header->command_code = cmd;
    header->body_size = body_size;
    memcpy(header->user_uuid, uuid, sizeof(header->user_uuid));
}

size_t get_packet_size(header_t const *packet)
{
    return sizeof(*packet) + packet->body_size;
}
