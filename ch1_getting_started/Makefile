CC = g++
CFLAG = -Wall -Werror -D_GLIBCXX_DEBUG -std=c++0x -g
COMPILE = $(CC) $(CFLAG) -c
OBJFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
PROG_NAME = InterestCalculator

all: myprog

myprog: $(OBJFILES)
	$(CC) -o $(PROG_NAME) $(OBJFILES)

%.o: %.cpp
	$(COMPILE) -o $@ $<

clean:
	rm -f *.o *.html $(PROG_NAME)