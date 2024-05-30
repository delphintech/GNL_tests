CC = cc

CFLAGS += -Werror -Wall -Wextra -D BUFFER_SIZE=10

NAME = test

BONUS = bonus

SRCS = test.c \
	get_next_line.c \
	get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

BSRCS =	test_bonus.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c

all	:	$(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

$(BOBJS): $(BSRCS)
	$(CC) $(CFLAGS) -c $(BSRCS)

$(BONUS):	$(BOBJS)
		$(CC) -o $(BONUS) $(BOBJS)

clean	:                 
		rm -f $(OBJS) $(BOBJS)

fclean	:	clean
		rm -f $(NAME) $(BONUS)
		
re	:	fclean all

debug : 
	$(CC) -g -o $(NAME)  $(SRCS)
	lldb ./$(NAME)

bdebug : 
	$(CC) -g -o $(BONUS) $(BSRCS)
	lldb ./$(BONUS)

val : 
	$(CC) -g3 -o $(NAME) $(SRCS)
	valgrind --leak-check=full --track-origins=yes -s ./$(NAME)

bval : 
	$(CC) -g3 -o $(BONUS) $(BSRCS)
	valgrind --leak-check=full --track-origins=yes -s ./$(BONUS)
	
.PHONY: all clean fclean re