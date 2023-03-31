NAME = RPN

OBJECTS_FOLDER = ./objects/

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:%.cpp=$(OBJECTS_FOLDER)%.o)

HEADERS = $(wildcard *.hpp)

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

RM = rm -rf

all: objs $(NAME)

$(OBJECTS_FOLDER)%.o: %.cpp $(PRE_HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $? -o $(NAME)

objs:
	@(mkdir -p objects)

clean:
	@$(RM) $(OBJECTS_FOLDER)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re