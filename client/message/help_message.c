/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <string.h>
#include "client.h"

static const char *help = "/help\n"\
"/login [\'user_name\']\n"\
"/logout\n"\
"/users\n"\
"/user [\'user_uuid\']\n"\
"/send [\'user_uuid\'] [\'message_body\']\n"\
"/messages [\'user_uuid\']\n"\
"/subscribe [\'team_uuid\']\n"\
"/subscribed ?[\'team_uuid\']\n"\
"/unsubscribe [\'team_uuid\']\n"\
"/use ?[\'team_uuid\'] ?[\'channel_uuid\'] ?[\'thread_uuid\']\n"\
"/create\n"\
"list\n"\
"info\n";


void help_message(myteams_t *m, char **params)
{
    printf(help);
}
