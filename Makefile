CC = gcc

CFLAGS = -Wall -Wextra -Werror

SNAME = server

SBNAME = server_bonus

CNAME = client

CBNAME = client_bonus

C_SRCS = 	client.c	\
		utils.c

C_B_SRCS =	client_bonus.c	\
		utils.c

S_SRCS =	server.c	\
		utils.c


S_B_SRCS =	server_bonus.c	\
		utils.c


all: $(SNAME) $(CNAME)

bonus: $(SBNAME) $(CBNAME)

clean:
	@echo cleaned

fclean:
	rm -rf $(SNAME)
	rm -rf $(CNAME)
	rm -rf $(SBNAME)
	rm -rf $(CBNAME)

$(SNAME):
	$(CC) $(CFLAGS) $(S_SRCS) -o $(SNAME)


$(SBNAME):
	$(CC) $(CFLAGS) $(S_B_SRCS) -o $(SBNAME)


$(CNAME):
	$(CC) $(CFLAGS) $(C_SRCS) -o $(CNAME)

$(CBNAME):
	$(CC) $(CFLAGS) $(C_B_SRCS) -o $(CBNAME)

re: fclean all

.PHONY: all clean fclean re bonus
