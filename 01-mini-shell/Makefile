CC=gcc
CFLAGS=-Wall -Wextra -std=c99
TARGET=mini-shell

all: $(TARGET)

$(TARGET): main.o shell.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o shell.o

clean:
	rm -f *.o $(TARGET)