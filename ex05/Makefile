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


NAME = ex05
#NAME_LIB = $(NAME)_lib
ASAN = $(NAME)_asan
#TEST = $(NAME)_test

SRCS = src/main.cpp src/Karen.cpp

OBJS = $(SRCS:.cpp=.o)
#LIB_OBJS = $(LIB_SRCS:.cpp=.o)
#TEST_OBJS = $(TEST_SRCS:.cpp=.o)

CXX = clang++
#GXX = g++
#LIB_CXX = ar rvs

CXXFLAGS = -Wall -Wextra -Werror  -std=c++03
#GXXFLAGS = -lgtest -lgtest_main -pthread
ASANFLAGS = -g -fsanitize=address

all: $(NAME)

asan: $(ASAN)
	./$(ASAN)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(ASAN): $(OBJS)
	$(CXX) $(ASANFLAGS) $(CXXFLAGS) $(OBJS) -o $(ASAN)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

#$(NAME_LIB): $(LIB_OBJS)
#	$(LIB_CXX) $(NAME_LIB) $(LIB_OBJS)

#$(TEST): $(TEST_OBJS) $(NAME_LIB)
#	$(GXX) $(GXXFLAGS) $(TEST_OBJS) $(NAME_LIB)  -o $(TEST)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#test/%.o: test/%.cpp
#	$(GXX) $(GXXFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS)
	@rm -fr $(TEST_OBJS)

fclean: clean
	@rm -fr $(NAME)
	@#rm -fr $(TEST)
	@#rm -fr $(NAME_LIB)
	@rm -fr $(ASAN)

re:
	@$(MAKE) fclean
	@$(MAKE) all
