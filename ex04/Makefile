#
#   /$$$$$$                             /$$$$$$    /$$  
#  /$$__  $$                           /$$$_  $$ /$$$$  
# | $$  \__/  /$$$$$$   /$$$$$$       | $$$$\ $$|_  $$  
# | $$       /$$__  $$ /$$__  $$      | $$ $$ $$  | $$  
# | $$      | $$  \ $$| $$  \ $$      | $$\ $$$$  | $$  
# | $$    $$| $$  | $$| $$  | $$      | $$ \ $$$  | $$  
# |  $$$$$$/| $$$$$$$/| $$$$$$$/      |  $$$$$$/ /$$$$$$
#  \______/ | $$____/ | $$____/        \______/ |______/
#           | $$      | $$                              
#           | $$      | $$                              
#           |__/      |__/                              
#


NAME = replace

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
