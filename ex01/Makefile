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

CXXFLAGS = -Wall -Wextra -Werror  -std=c++03
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

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(NAME_LIB): $(LIB_OBJS)
	$(LIB_CXX) $(NAME_LIB) $(LIB_OBJS)

$(TEST): $(TEST_OBJS) $(NAME_LIB)
	$(GXX) $(GXXFLAGS) $(TEST_OBJS) $(NAME_LIB)  -o $(TEST)

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
