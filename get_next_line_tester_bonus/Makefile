# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -g

# Source files
SRCS = main_test.c ../get_next_line_utils_bonus.c ../get_next_line_bonus.c
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = ../get_next_line_bonus.h

# Executable name
NAME = test_program

# Buffer sizes to test
BUFFER_SIZES = 1 10 100 512 1024

# Rule to compile and test with different BUFFER_SIZE values
all: $(BUFFER_SIZES)

$(OBJS): $(SRCS) $(HEADERS)

$(BUFFER_SIZES):
	@echo "Testing with BUFFER_SIZE=$@"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$@ -o $(NAME) $(SRCS)
	@./$(NAME)
	@echo "\n--------------------------------"

# Clean rule
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
