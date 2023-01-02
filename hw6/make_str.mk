CC=g++
CCLINK=$(CC)
CFLAGS=-std=c++11 -g -Wall
OBJS=main_str.o string.o
EXEC=prog_str.exe
RM=rm -rf

# The first rule -> prog.exe
$(EXEC): $(OBJS)
	$(CCLINK) $(OBJS) -o $(EXEC)


# Ineternal Dependencies

main_str.o: main_str.cpp string.h
	$(CC) $(CFLAGS) -c main_str.cpp

string.o: string.cpp string.h
	$(CC) $(CFLAGS) -c string.cpp


clean:
	$(RM) *.o *.exe


