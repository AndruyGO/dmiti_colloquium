CXX = g++
CXXFLAGS = -std=c++17

TARGET = prog
OBJECTS = obj/main.o obj/Module_1/*.o obj/Module_2/*.o

all:
	$(CXX) $(CXXFLAGS) -c main.cpp
	mv main.o obj/
	$(CXX) $(CXXFLAGS) -c Module_1/*.cpp
	mv *.o obj/Module_1/
	$(CXX) $(CXXFLAGS) -c Module_2/*.cpp
	mv *.o obj/Module_2/
	$(CXX) $(OBJECTS) -o $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
