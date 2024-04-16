/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** user_req
*/

#ifndef USER_REQ_H
    #define USER_REQ_H

    #include "utils.h"

typedef struct PACKED user_request_body_s {
    uuID_t uuid;
} user_request_body_t;

typedef struct PACKED user_request_s {
    header_t header;
    user_request_body_t body;
} user_request_t;

typedef struct PACKED user_response_body_s {
    uuID_t uuid;
    username_t username;
    uint8_t status;
} user_response_body_t;

typedef struct PACKED user_response_s {
    header_t header;
    user_response_body_t body;
} user_response_t;

#endif /* USER_REQ_H */
