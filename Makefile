CXX = g++
CXXFLAGS = -std=c++20 -Iheaders -g -I/opt/homebrew/opt/googletest/include
LDLIBS = -lgtest -lgtest_main -pthread

SRC_DIR = src
TEST_DIR = tests

SRCS = $(SRC_DIR)/Task.cpp $(SRC_DIR)/TaskManager.cpp $(SRC_DIR)/User.cpp $(SRC_DIR)/main.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRC = $(TEST_DIR)/tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

TARGET = Task_Manager
TEST_TARGET = test_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(OBJS) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TEST_TARGET) $^ $(LDLIBS)

run_tests: test
	./$(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJ)
