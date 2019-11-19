.SUFFIXES: .cpp .o

OBJECTS = test.o human.o student.o smart_obj.o shared_ref.o weak_pointer.o

CXX = g++
CPPFLAGS = -c

TARGET = test3

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

test.o : test.cpp
human.o : human.cpp
student.o : student.cpp
smart_obj.o : smart_obj.cpp
shared_ref.o : shared_ref.cpp
weak_pointer.o : weak_pointer.cpp
