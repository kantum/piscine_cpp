NAME = megaphone
CC = clang
CXX = clang++
RM = rm -f
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
LDFLAGS = -g
LDLIBS =
LD = ld
SRCS = megaphone.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: $(NAME)

%.o: %.cpp
	@$(CXX) $(CPPFLAGS) -c $<

$(NAME): $(OBJS)
	@$(CXX) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
