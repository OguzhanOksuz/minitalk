CC = gcc

CFLAGS = -Wall -Wextra -Werror

SNAME = server

CNAME = client

C_SRCS = client.c

S_SRCS = server.c

all: $(SNAME) $(CNAME)

clean:
	rm -rf $(SNAME)
	rm -rf $(CNAME)


fclean:
	rm -rf $(SNAME)
	rm -rf $(CNAME)

$(SNAME):
	$(CC) $(CFLAGS) $(S_SRCS) -o $(SNAME)

$(CNAME):
	$(CC) $(CFLAGS) $(C_SRCS) -o $(CNAME)

re: clean all

.PHONY: all clean fclean re
