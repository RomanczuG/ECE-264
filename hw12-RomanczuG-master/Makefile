WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

TESTFALGS = -DTEST_CREATELIST -DTEST_ELIMINATE -DTEST_DELETENODE -DDEBUG

SRCS = hw12.c calc.c
OBJS = $(SRCS:%.c=%.o)

hw12: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw12

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5

all: hw12

test1: hw12
	./hw12 inputs/test1

test2: hw12
	./hw12 inputs/test2

test3: hw12
	./hw12 inputs/test3

test4: hw12
	./hw12 inputs/test4

test5: hw12
	./hw12 inputs/test5

test6: hw12
	./hw12 inputs/test7

memory: hw12
	$(VALGRIND) --log-file=log1 ./hw12 inputs/test1
	$(VALGRIND) --log-file=log2 ./hw12 inputs/test2
	$(VALGRIND) --log-file=log3 ./hw12 inputs/test3
	$(VALGRIND) --log-file=log4 ./hw12 inputs/test4 
	$(VALGRIND) --log-file=log5 ./hw12 inputs/test5
	$(VALGRIND) --log-file=log6 ./hw12 inputs/test6

clean: # remove all machine generated files
	rm -f hw12 *.o output?


