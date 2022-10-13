CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = -DTEST_SHUFFLE -DTEST_INTERLEAVE -DTEST_DIVIDE  
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = program
OBJS =  main.o shuffle.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) shuffle.h
	$(GCC) $(OBJS) -o $(EXEC) 


test: $(EXEC)
	./$(EXEC) 4 > output4
	./$(EXEC) 8 > output8
	./$(EXEC) 11 > output11
test2: $(EXEC)
	./$(EXEC) 4 | sort > output4
	diff -w output4 expected/expected4
	./$(EXEC) 8 | sort > output8
	diff -w output8 expected/expected8
	./$(EXEC) 11 | sort > output11
	diff -w output11 expected/expected11
testDiff: $(EXEC)
	diff -w output4 expected/expected4
	diff -w output8 expected/expected8
	diff -w output11 expected/expected11
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 4

%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f id? first? last? log?