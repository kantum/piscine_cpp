NAME = ft_retro
CC = clang
CXX = clang++
RM = rm -f
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address
LDFLAGS = -g -lncurses -fsanitize=address#-v
SRCS = Character.cpp Enemy.cpp Game.cpp Player.cpp Menu.cpp Projectile.cpp main.cpp
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
