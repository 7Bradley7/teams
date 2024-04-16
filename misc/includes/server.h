/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef SERVER_H
    #define SERVER_H

    #include "utils.h"
    #include "macro.h"
    #include "logging_server.h"

typedef struct server_s {
    socket_t sk;
    fd_set read_fds;
    int mfd;
    int port;
} server_t;

typedef struct myteams_s {
    server_t s;
    client_t *c;
} myteams_t;

void init_server(myteams_t *m);
void init_clients(myteams_t *m);
void message_client(myteams_t *m);
void handle_message(myteams_t *m, int id);
void link_client(myteams_t *m);
void select_client(myteams_t *m);
void connect_client(myteams_t *m);
void server_loop(myteams_t *m);

void help_command(myteams_t *m, client_t *c);
void login_command(myteams_t *m, client_t *c);
void logout_command(myteams_t *m, client_t *c);
void users_command(myteams_t *m, client_t *c);
void user_command(myteams_t *m, client_t *c);
void send_command(myteams_t *m, client_t *c);
void messages_command(myteams_t *m, client_t *c);
void subscribe_command(myteams_t *m, client_t *c);
void subscribed_command(myteams_t *m, client_t *c);
void unsubscribe_command(myteams_t *m, client_t *c);
void use_command(myteams_t *m, client_t *c);
void create_command(myteams_t *m, client_t *c);
void list_command(myteams_t *m, client_t *c);
void info_command(myteams_t *m, client_t *c);

void create_logs(void);
void write_in_logins_log(char *username, char *uuid);
char **parse_logins_by_username(char *username);
char **parse_logins_by_uuid(char *uuid);

void close_clients_till_index(myteams_t *m, int index);
void close_clients(myteams_t *m);
void close_server(myteams_t *m, char *error_str, int exit_code);

#endif /* SERVER_H */
