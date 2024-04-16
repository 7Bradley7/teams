/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** message_db
*/

#ifndef MESSAGE_DB_H_
    #define MESSAGE_DB_H_

    #include "utils.h"

typedef struct PACKED message_s {
    char sender[MAX_UUID_LENGTH];
    uint64_t time;
    uint16_t msg_size;
    char msg[MAX_MESSAGE_LENGTH];
} message_t;

typedef struct PACKED conversation_s {
    uint32_t nb_msg;
    char uuid1[MAX_UUID_LENGTH];
    char uuid2[MAX_UUID_LENGTH];
    message_t messages[MAX_MESSAGES_PER_CONV];
} conv_t;

#endif /* !MESSAGE_DB_H_ */
