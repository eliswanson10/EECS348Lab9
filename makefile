CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = lab9
SRC = lab9.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
