##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## make re all clean fclean
##

all:
	$(MAKE) -C client/
	$(MAKE) -C server/
	mv client/myteams_cli .
	mv server/myteams_server .

clean:
	$(MAKE) -C client/ clean
	$(MAKE) -C server/ clean

fclean: clean
	$(MAKE) -C client/ fclean
	$(MAKE) -C server/ fclean
	$(RM) myteams_cli
	$(RM) myteams_server
	$(RM) client/coding-style-reports.log
	$(RM) server/coding-style-reports.log
	rm -rf logs/

coding-style: fclean
	@./bananas server/ server/
	@./bananas client/ client/
	clear
	@cat client/coding-style-reports.log
	@cat server/coding-style-reports.log

re: fclean all

.PHONY: re all clean fclean coding-style
