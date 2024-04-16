/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** user_req
*/

#ifndef USER_REQ_H
    #define USER_REQ_H

    #include "utils.h"

typedef struct PACKED users_response_body_s {
    char username[MAX_USERNAME_LENGTH];
    char uuid[MAX_UUID_LENGTH];
    bool is_logged;
} users_response_body_t;

typedef struct PACKED users_response_s {
    header_t header;
    users_response_body_t body;
} users_response_t;

#endif /* USER_REQ_H */
