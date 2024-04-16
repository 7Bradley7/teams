##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make re all run_test clean fclean
##

NAME	=	myteams_server

SRC_MISC	=	../misc/src/logs_managment.c		\
				../misc/src/protocol_management.c	\
				../misc/src/strtwa.c				\
				../misc/src/close_server.c			\
				../misc/src/utils.c					\
				../misc/src/packet_utils.c			\
				../misc/src/print_utils.c			\
				../misc/src/message_db.c			\

SRC	=	main.c								\
		server.c							\
		init/init_server.c					\
		init/init_clients.c					\
		clients_handling/select_client.c	\
		clients_handling/message_client.c	\
		clients_handling/link_client.c		\
		clients_handling/connect_client.c	\
		clients_handling/handle_message.c

SRC_COMMAND =	commands/users_command.c		\
				commands/login_command.c		\
				commands/subscribed_command.c	\
				commands/messages_command.c		\
				commands/unsubscribe_command.c	\
				commands/use_command.c			\
				commands/create_command.c		\
				commands/logout_command.c		\
				commands/subscribe_command.c	\
				commands/user_command.c			\
				commands/send_command.c			\
				commands/list_command.c			\
				commands/help_command.c			\
				commands/info_command.c

OBJ	=	$(SRC:.c=.o)
OBJ_COMMAND	=	$(SRC_COMMAND:.c=.o)
OBJ_MISC	=	$(SRC_MISC:.c=.o)

CPPFLAGS	+=	-I../misc/includes
CPPFLAGS	+=	-I../libs/myteams
LDFLAGS	+=	-L../libs/myteams/
LDLIBS	+=	-lmyteams -luuid

CFLAGS	+=	-g

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MISC) $(OBJ_COMMAND)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MISC) $(OBJ_COMMAND) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ) $(OBJ_MISC) $(OBJ_COMMAND)

fclean: clean
	$(RM) $(NAME)
	$(RM) coding-style-reports.log

re: fclean all

.PHONY: re all clean fclean
