NAME = phonebook
CC = clang
CXX = clang++
RM = rm -f
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
LDFLAGS = -g
LDLIBS =
SRCS = main.cpp contact.class.cpp
HEADERS = -I./
OBJS = $(subst .cpp,.o,$(SRCS))

all: $(NAME)

%.o: %.cpp
	@$(CXX) $(CPPFLAGS) -c $<

$(NAME): $(OBJS)
	@$(CXX) $(LDFLAGS) $(HEADERS) $(OBJS) $(LDLIBS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
