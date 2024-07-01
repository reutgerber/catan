# #322516840 reutgerber@gmail.com



CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I include -I /usr/local/include

# קבצים מקוריים
SRC_FILES = Demo.cpp board.cpp catan.cpp develope_card.cpp Edge.cpp hexagon.cpp Vertex.cpp player.cpp print.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
EXECUTABLE = catan

# קבצי בדיקות
TEST_SRC_FILES = test.cpp
TEST_OBJ_FILES = $(TEST_SRC_FILES:.cpp=.o)
TEST_EXECUTABLE = test

# כלל ברירת מחדל
all: $(EXECUTABLE) #$(TEST_EXECUTABLE) 

# בניית התוכנית הראשית
$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# בניית בדיקות
$(TEST_EXECUTABLE): $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lgtest -lgtest_main -pthread

# בניית קבצי אובייקט
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ניקוי קבצים שנבנו
clean:
	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_OBJ_FILES) $(TEST_EXECUTABLE)

# בדיקות קוד עם clang-tidy
tidy:
	clang-tidy $(SRC_FILES) -- -std=c++11 -I include

# בדיקות זיכרון עם Valgrind
valgrind: $(EXECUTABLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)
