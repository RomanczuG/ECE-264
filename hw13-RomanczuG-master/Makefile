WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

TESTFALGS = 

SRCS = hw13.c scanner.c tree.c expressionTree.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS) expressionTree.h tree.h scanner.h
	$(GCC) $(TESTFALGS) $(OBJS) -o hw13

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4

all: hw13

test1: hw13
	./hw13 inputs/test1 output1

test2: hw13
	./hw13 inputs/test2 output2

test3: hw13
	./hw13 inputs/test3 output3

test4: hw13
	./hw13 inputs/test4 output4


memory: hw12
	$(VALGRIND) --log-file=log1 ./hw12 inputs/test1
	$(VALGRIND) --log-file=log2 ./hw12 inputs/test2
	$(VALGRIND) --log-file=log3 ./hw12 inputs/test3
	$(VALGRIND) --log-file=log4 ./hw12 inputs/test4 
	$(VALGRIND) --log-file=log5 ./hw12 inputs/test5
	$(VALGRIND) --log-file=log6 ./hw12 inputs/test6

clean: # remove all machine generated files
	rm -f hw12 *.o output?


