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

string.o: string.cpp string.h

clean:
	$(RM) *.o *.exe


