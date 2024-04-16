/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef UTILS_H
    #define UTILS_H

    #include <stdio.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <macro.h>

    #define COPY_USERNAME(str) cpy_fixed((str), MAX_USERNAME_LENGTH)
    #define COPY_UUID(str) cpy_fixed((str), MAX_UUID_LENGTH)
    #define PACKED __attribute__((packed))
    #define HEADER_SIZE sizeof(header_t)
    #define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef char uuID_t[MAX_UUID_LENGTH];
typedef char username_t[MAX_USERNAME_LENGTH];

typedef enum function_code_s {
    HELP_CODE,
    LOGIN_CODE,
    LOGOUT_CODE,
    USERS_CODE,
    USER_CODE,
    SEND_CODE,
    MESSAGES_CODE,
    SUBSCRIBE_CODE,
    SUBSCRIBED_CODE,
    UNSUBSCRIBE_CODE,
    USE_CODE,
    CREATE_CODE,
    LIST_CODE,
    INFO_CODE,
    READY_TO_DISCONNECT
} function_code_t;

typedef enum error_code_s {
    NO_ERROR,
    USER_ALREADY_LOGGED_IN,
    TOO_MUCH_PARAMS,
    MISSING_PARAMS,
    NOT_LOGGED_IN,
    UNCOHERENT_UUID,
    INVALID_PARAMS,
    REQUESTED_USER_NOT_FOUND,
    UNKNOWN
} error_code_t;

typedef struct PACKED header_s {
    uint8_t command_code;
    uint8_t error_code;
    char user_uuid[MAX_UUID_LENGTH];
    uint16_t body_size;
} header_t;

typedef struct socket_s {
    int fd;
    struct sockaddr_in addr_in;
} socket_t;

typedef struct user_s {
    char username[MAX_USERNAME_LENGTH];
    char uuid[MAX_UUID_LENGTH];
    char *password;
    bool is_logged;
} user_t;

typedef struct PACKED login_body_s {
    char username[MAX_USERNAME_LENGTH];
    char uuid[MAX_UUID_LENGTH];
} login_body_t;

typedef struct PACKED login_s {
    header_t h;
    login_body_t body;
} login_t;

typedef struct PACKED login_response_body_s {
    char uuid[MAX_UUID_LENGTH];
    char username[MAX_USERNAME_LENGTH];
} login_response_body_t;

typedef struct PACKED login_response_s {
    header_t header;
    login_response_body_t body;
} login_response_t;

typedef struct client_s {
    user_t u;
    socket_t sk;
    header_t *h;
} client_t;

void init_packet(header_t *header, uint16_t body_size, uuID_t const uuid
    , u_int8_t cmd);

char **strtwa(char *str, char *token);
int get_nbr_wa(char **wa);
char *watstr(char **wa);

void assign_code(header_t *h, u_int8_t command_code, u_int8_t error_code);
void send_error_by_protocol(client_t *c, u_int8_t c_code, u_int8_t e_code);
void send_normal_by_protocol(client_t *c, header_t *packet);

char *cpy_fixed(char const *str, size_t const len);

char const *get_cmd_name(uint8_t name);
char const *get_err_msg(uint8_t err);

bool uuid_eq(uuID_t const a, uuID_t const b);
bool username_eq(username_t const a, username_t const b);

bool send_packet(int fd, header_t const *packet);

#endif /* UTILS_H */
