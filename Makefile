CC = gcc

CFLAGS = -Wall -Wextra -Werror

SNAME = server

CNAME = client

C_SRCS = 	client.c	\
		utils.c

S_SRCS =	server.c	\
		utils.c

all: $(SNAME) $(CNAME)

clean:


fclean:
	rm -rf $(SNAME)
	rm -rf $(CNAME)

$(SNAME):
	$(CC) $(CFLAGS) $(S_SRCS) -o $(SNAME)

$(CNAME):
	$(CC) $(CFLAGS) $(C_SRCS) -o $(CNAME)

re: fclean all

.PHONY: all clean fclean re
