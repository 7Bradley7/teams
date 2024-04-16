/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef CLIENT_H
    #define CLIENT_H

    #include "utils.h"
    #include "macro.h"
    #include "logging_client.h"

typedef struct message_s {
    char *message;
    int len;
} message_t;

typedef struct server_s {
    socket_t sk;
    fd_set read_fds;
    int mfd;
    int port;
    char *ip;
} server_t;

typedef struct myteams_s {
    server_t s;
    client_t c;
    message_t m;
} myteams_t;

void init_server(myteams_t *m);
void init_client(myteams_t *m);
void handle_command(myteams_t *m);
void handle_message(myteams_t *m);
void handle_client(myteams_t *m);
void client_loop(myteams_t *m);

void help_message(myteams_t *m, char **params);
void login_message(myteams_t *m, char **params);
void logout_message(myteams_t *m, char **params);
void users_message(myteams_t *m, char **params);
void user_message(myteams_t *m, char **params);
void send_message(myteams_t *m, char **params);
void messages_message(myteams_t *m, char **params);
void subscribe_message(myteams_t *m, char **params);
void subscribed_message(myteams_t *m, char **params);
void unsubscribe_message(myteams_t *m, char **params);
void use_message(myteams_t *m, char **params);
void create_message(myteams_t *m, char **params);
void list_message(myteams_t *m, char **params);
void info_message(myteams_t *m, char **params);

void help_command(myteams_t *m);
void login_command(myteams_t *m);
void logout_command(myteams_t *m);
void users_command(myteams_t *m);
void user_command(myteams_t *m);
void send_command(myteams_t *m);
void messages_command(myteams_t *m);
void subscribe_command(myteams_t *m);
void subscribed_command(myteams_t *m);
void unsubscribe_command(myteams_t *m);
void use_command(myteams_t *m);
void create_command(myteams_t *m);
void list_command(myteams_t *m);
void info_command(myteams_t *m);

void close_client(client_t *c);
void close_server(myteams_t *m, char *error_str, int exit_code);

#endif /* CLIENT_H */
