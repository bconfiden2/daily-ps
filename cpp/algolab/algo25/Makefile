CC = g++
CFLAGS =


OBJS = MyHammingCode.o TestMyHammingCode.o

TARGET = algo25

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

MyHammingCode.o : MyHammingCode.cpp MyHammingCode.h
	$(CC) -c MyHammingCode.cpp

TestMyHammingCode.o : TestMyHammingCode.cpp MyHammingCode.h
	$(CC) -c TestMyHammingCode.cpp

clean :
	rm -rf $(TARGET) $(OBJS)
run :
	./$(TARGET) < InputFile
