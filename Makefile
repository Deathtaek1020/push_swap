CC=cc
CFLAGS=-Wall -Wextra -Werror

NAME=push_swap

INCDIR=includes
SRCDIR=src
LIBDIR=lib/mini_libft

INCS=$(INCDIR)/push_swap.h

SRCS= \
	$(SRCDIR)/main.c \
	$(SRCDIR)/parse.c \
	$(SRCDIR)/ops.c \
	$(SRCDIR)/stack.c \
	$(SRCDIR)/radix.c

LIBSRCS= \
	$(LIBDIR)/ft_split.c \
	$(LIBDIR)/ft_utils.c

OBJS=$(SRCS:.c=.o) $(LIBSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	 rm -f $(OBJS)

fclean: clean
	 rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
