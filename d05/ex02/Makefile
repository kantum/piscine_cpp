NAME = Form
CC = clang
CXX = clang++
RM = rm -f
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
LDFLAGS = -g
SRCS = Bureaucrat.cpp \
	   Form.cpp \
	   PresidentialPardonForm.cpp \
	   RobotomyRequestForm.cpp \
	   ShrubberyCreationForm.cpp \
	   main.cpp

HEADERS = -I./
OBJS = $(subst .cpp,.o,$(SRCS))

all: $(NAME)

%.o: %.cpp
	@$(CXX) $(CPPFLAGS) -c $<

$(NAME): $(OBJS)
	@$(CXX) $(LDFLAGS) $(HEADERS) $(OBJS) $(LDLIBS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@rm -f home

fclean: clean
	@$(RM) $(NAME)

re: fclean all
