/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** packet_utils
*/

#ifndef PACKET_UTILS_H
    #define PACKET_UTILS_H

    #include "utils.h"

bool send_packet(int fd, header_t const *packet);
void init_packet(header_t *header, uint16_t body_size, uuID_t const uuid,
    u_int8_t cmd);
size_t get_packet_size(header_t const *packet);

#endif /* PACKET_UTILS_H */
