CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = string_calc_program
OBJS = main.o string_calc.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp string_calc.h
	$(CXX) $(CXXFLAGS) -c main.cpp

string_calc.o: string_calc.cpp string_calc.h
	$(CXX) $(CXXFLAGS) -c string_calc.cpp

clean:
	rm -f *.o $(TARGET)
