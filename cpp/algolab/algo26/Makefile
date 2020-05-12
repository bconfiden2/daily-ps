CC = g++

OBJS = TestMyHammingDistance.o MyHammingDistance.o

TARGET = 26

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

TestMyHammingDistance.o : TestMyHammingDistance.cpp MyHammingDistance.h
	$(CC) -c TestMyHammingDistance.cpp

MyHammingDistance.o : MyHammingDistance.cpp MyHammingDistance.h
	$(CC) -c MyHammingDistance.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET) < InputFile
