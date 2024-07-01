# #322516840 reutgerber@gmail.com
# #!make -f
# #task2
# CXX=c++
# CXXFLAGS=-std=c++11 #-g -I #-Werror -Wsign-conversion
# #VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# SOURCES=Demo.cpp board.cpp Catan.cpp develope_card.cpp Edge.cpp hexagon.cpp Vertex.cpp player.cpp print.hpp test.cpp

# OBJECTS=$(subst .cpp,.o,$(SOURCES))


# run: test #demo
# 	./$^

# demo: Demo.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o demo

# test: test.o $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) $^ -o test

# tidy:
# 	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# valgrind: demo #test
# 	valgrind --leak-check=full --show-leak-kinds=all ./demo
# #	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) --compile $< -o $@

# clean:
# 	rm -f *.o demo
#hila
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I include -I /usr/local/include
# SRC_FILES = Demo.cpp board.cpp catan.cpp develope_card.cpp Edge.cpp hexagon.cpp Vertex.cpp player.cpp print.cpp
# OBJ_FILES = $(SRC_FILES:.cpp=.o)
# EXECUTABLE = catan

# TEST_SRC_FILES = test.cpp
# TEST_OBJ_FILES = $(TEST_SRC_FILES:.cpp=.o)
# TEST_EXECUTABLE = test

# test: $(TEST_EXECUTABLE)
# #catan: $(EXECUTABLE)

# $(EXECUTABLE): $(OBJ_FILES)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# $(TEST_EXECUTABLE): $(filter-out Demo.o, $(OBJ_FILES)) $(TEST_OBJ_FILES)
# 	$(CXX) $(CXXFLAGS) $^ -o $@  -lgtest -lgtest_main -pthread

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ_FILES) $(EXECUTABLE) $(TEST_OBJ_FILES) $(TEST_EXECUTABLE)
# #rm -f *.o test
 

# tidy:
# 	clang-tidy $(SRC_FILES) -- -std=c++11 -I include

# valgrind: $(EXECUTABLE)
# 	valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)


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