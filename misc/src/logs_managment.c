/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

void create_logs(void)
{
    int fd = open("logs/logins.log", O_RDWR | O_CREAT, 0666);

    if (fd == ERROR) {
        printf("create logs\n");
    }
    close(fd);
}

static char *create_line(char *username, char *uuid)
{
    char *line = calloc(strlen(username) + strlen(uuid) + 3, sizeof(char));
    int i = 0;

    for (int j = 0; username[j] && j < MAX_USERNAME_LENGTH; j++) {
        line[i] = username[j];
        i++;
    }
    line[i] = ' ';
    i++;
    for (int j = 0; uuid[j] && j < MAX_USERNAME_LENGTH; j++) {
        line[i] = uuid[j];
        i++;
    }
    line[i] = '\n';
    return (line);
}

void write_in_logins_log(char *username, char *uuid)
{
    char *line = create_line(username, uuid);
    FILE *fptr = fopen("logs/logins.log", "a");

    if (fptr == NULL) {
        printf("fopen when writing\n");
        return;
    }
    fprintf(fptr, line);
    fclose(fptr);
}

static char **split_all_logs(int fd)
{
    char *logs = calloc(MAX_LOGS_LENGTH, sizeof(char));
    ssize_t len = read(fd, logs, MAX_LOGS_LENGTH);

    if (len == ERROR) {
        printf("read logs\n");
        return (NULL);
    }
    return (strtwa(logs, "\n"));
}

char **parse_logins_by_username(char *username)
{
    int fd = open("logs/logins.log", 0);
    char **all_logs;
    char **wa;

    if (fd == ERROR) {
        return (NULL);
    }
    all_logs = split_all_logs(fd);
    if (all_logs == NULL) {
        return (NULL);
    }
    for (int i = 0; all_logs[i]; i++) {
        wa = strtwa(all_logs[i], "  \n");
        if (wa != NULL && strcmp(wa[0], username) == SUCCESS) {
            close(fd);
            return (wa);
        }
    }
    close(fd);
    return (NULL);
}

char **parse_logins_by_uuid(char *uuid)
{
    int fd = open("logs/logins.log", 0);
    char **all_logs;
    char **wa;

    if (fd == ERROR) {
        return (NULL);
    }
    all_logs = split_all_logs(fd);
    if (all_logs == NULL) {
        return (NULL);
    }
    for (int i = 0; all_logs[i]; i++) {
        wa = strtwa(all_logs[i], "  \n");
        if (wa != NULL && strcmp(wa[1], uuid) == SUCCESS) {
            close(fd);
            return (wa);
        }
    }
    close(fd);
    return (NULL);
}
