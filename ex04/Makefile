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
ASAN = $(NAME)_asan

SRCS = src/main.cpp  src/ReplaceAssert.cpp  src/Replacer.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror  -std=c++98
ASANFLAGS = -g -fsanitize=address

all: $(NAME)

asan: $(ASAN)
	./$(ASAN)

valgrnd: $(NAME)
	valgrind ./$(NAME)

test: $(NAME)
	sh resources/test.sh

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(ASAN): $(OBJS)
	$(CXX) $(ASANFLAGS) $(CXXFLAGS) $(OBJS) -o $(ASAN)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)
	@rm -fr resources/*.replace

fclean: clean
	@rm -fr $(NAME)
	@rm -fr $(ASAN)

re:
	@$(MAKE) fclean
	@$(MAKE) all
