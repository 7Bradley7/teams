/*
** EPITECH PROJECT, 2024
** B-NWP-400-PAR-4-1-myteams-erwann.wicart
** File description:
** message_db
*/

#include <time.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <macro.h>
#include <fcntl.h>
#include <unistd.h>
#include "message_db.h"

static char const *const log_dir = "/logs/conv/";
static char const *const uuid_sep = "_";
static char const *const conv_ext = ".conv";

static char *get_conv_path(char const *uuid1, char const *uuid2)
{
    char const *fst;
    char const *snd;
    char *path = calloc(sizeof(char), (strlen(log_dir) + strlen(fst)
        + strlen(snd) + strlen(uuid_sep) + strlen(conv_ext)));

    if (path == NULL)
        return NULL;
    if (strcmp(uuid1, uuid2) < 0) {
        fst = uuid1;
        snd = uuid2;
    } else {
        snd = uuid1;
        fst = uuid2;
    }
    strcat(path, log_dir);
    strcat(path, fst);
    strcat(path, uuid_sep);
    strcat(path, snd);
    strcat(path, conv_ext);
    return path;
}

static conv_t *create_conv(char const *uuid1, char const *uuid2)
{
    conv_t *conv = calloc(sizeof(*conv), 1);

    memset(conv, 0, sizeof(*conv));
    memcpy(conv->uuid1, uuid1, sizeof(char) * MAX_UUID_LENGTH);
    memcpy(conv->uuid2, uuid2, sizeof(char) * MAX_UUID_LENGTH);
    return conv;
}

static conv_t *read_conv(char const *path)
{
    int fd = open(path, O_RDONLY);
    conv_t *conv;

    if (fd < 0)
        return NULL;
    conv = calloc(sizeof(*conv), 1);
    if (read(fd, conv, sizeof(*conv)) < sizeof(*conv)) {
        free(conv);
        return NULL;
    }
    conv = realloc(conv, sizeof(*conv) + (conv->nb_msg
        * sizeof(*conv->messages)));
    memset(conv + 1, 0, conv->nb_msg * sizeof(*conv->messages));
    if (read(fd, conv + 1, conv->nb_msg * sizeof(*conv->messages))
        < conv->nb_msg * sizeof(*conv->messages)) {
        free(conv);
        return NULL;
    }
    return conv;
}

conv_t *get_conversation(char const *uuid1, char const *uuid2)
{
    char const *const path = get_conv_path(uuid1, uuid2);
    conv_t *conv = read_conv(path);

    free(path);
    if (conv == NULL)
        return create_conv(uuid1, uuid2);
    return conv;
}

bool save_conversation(conv_t *conv)
{
    char const *const path = get_conv_path(conv->uuid1, conv->uuid2);
    int fd = open(path, O_WRONLY);

    if (fd < 0)
        return false;
    if (write(fd, conv, sizeof(*conv)) < sizeof(*conv))
        return false;
    return true;
}

bool register_message(conv_t *conv, uuID_t const sender, char const *msg)
{
    message_t *message = (void *)conv->messages
        + ((conv->nb_msg + 1) * sizeof(message_t));

    conv->nb_msg++;
    if (conv->nb_msg == MAX_MESSAGES_PER_CONV)
        return false;
    memcpy(message->sender, sender, sizeof(message->sender));
    message->msg_size = strlen(msg);
    message->time = (uint64_t)time(NULL);
    memcpy(message->msg, msg, sizeof(char) * message->msg_size);
    return save_conversation(conv);
}
