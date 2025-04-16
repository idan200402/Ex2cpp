CppC = g++
CppCFLAGS = -std=c++11 -Wall 
TARGET = program
SOURCES = main.cpp squareMat.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = squareMat.h
TEST_SOURCES = test.cpp squareMat.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_TARGET = tests
# default target
all: $(TARGET)

#linking
$(TARGET): $(OBJECTS)
	$(CppC) $(CppCFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CppC) $(CppCFLAGS) -o $@ $^

# compiling
%.o: %.cpp $(HEADERS)
	$(CppC) $(CppCFLAGS) -c $< -o $@

#cleaning
clean:
	rm -f $(OBJECTS) $(TARGET) $(TEST_OBJECTS) $(TEST_TARGET)

#running
Main: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)