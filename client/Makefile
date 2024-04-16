##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make re all run_test clean fclean
##

NAME	=	myteams_cli

SRC_MISC	=	../misc/src/protocol_management.c	\
				../misc/src/close_server.c			\
				../misc/src/strtwa.c				\
				../misc/src/utils.c					\
				../misc/src/packet_utils.c			\
				../misc/src/print_utils.c			\

SRC	=	main.c								\
		client.c							\
		init/init_server.c					\
		init/init_clients.c					\
		client_handling/handle_client.c		\
		client_handling/handle_command.c	\
		client_handling/handle_message.c	\

SRC_MESSAGE	=	message/create_message.c		\
				message/subscribed_message.c	\
				message/send_message.c			\
				message/subscribe_message.c		\
				message/list_message.c			\
				message/login_message.c			\
				message/logout_message.c		\
				message/messages_message.c		\
				message/unsubscribe_message.c	\
				message/info_message.c			\
				message/user_message.c			\
				message/use_message.c			\
				message/users_message.c			\
				message/help_message.c			\

SRC_COMMAND	=	response/users_command.c		\
				response/login_command.c		\
				response/subscribed_command.c	\
				response/messages_command.c		\
				response/unsubscribe_command.c	\
				response/use_command.c			\
				response/create_command.c		\
				response/logout_command.c		\
				response/subscribe_command.c	\
				response/user_command.c			\
				response/send_command.c			\
				response/list_command.c			\
				response/help_command.c			\
				response/info_command.c			\

OBJ	=	$(SRC:.c=.o)
OBJ_MESSAGE	=	$(SRC_MESSAGE:.c=.o)
OBJ_COMMAND	=	$(SRC_COMMAND:.c=.o)
OBJ_MISC	=	$(SRC_MISC:.c=.o)

CPPFLAGS	+=	-I../misc/includes
CPPFLAGS	+=	-I../libs/myteams
LDFLAGS	+=	-L../libs/myteams/
LDLIBS	+=	-lmyteams -luuid

CFLAGS	+=	-g

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MISC) $(OBJ_MESSAGE) $(OBJ_COMMAND)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MISC)	\
	$(OBJ_MESSAGE) $(OBJ_COMMAND) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ) $(OBJ_MISC) $(OBJ_MESSAGE) $(OBJ_COMMAND)

fclean: clean
	$(RM) $(NAME)
	$(RM) coding-style-reports.log

re: fclean all

.PHONY: re all clean fclean
