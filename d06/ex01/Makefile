NAME = Serialize
CC = clang
CXX = clang++
RM = rm -f
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror # -fsanitize=address
LDFLAGS = -g
SRCS = main.cpp
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
