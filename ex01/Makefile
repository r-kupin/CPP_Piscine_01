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

NAME = ex01
ASAN = $(NAME)_asan

SRCS =  src/main.cpp src/Zombie.cpp src/ZombieHorde.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror  -std=c++98
ASANFLAGS = -g -fsanitize=address

all: $(NAME)

asan: $(ASAN)
	./$(ASAN)

valgrnd: $(NAME)
	valgrind ./$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(ASAN): $(OBJS)
	$(CXX) $(ASANFLAGS) $(CXXFLAGS) $(OBJS) -o $(ASAN)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test/%.o: test/%.cpp
	$(GXX) $(GXXFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)
	@rm -fr $(TEST_OBJS)

fclean: clean
	@rm -fr $(NAME)
	@rm -fr $(ASAN)

re:
	@$(MAKE) fclean
	@$(MAKE) all
