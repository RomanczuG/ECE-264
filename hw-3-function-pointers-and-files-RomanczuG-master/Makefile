CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror

FUNCS = func1.o func2.o func3.o func4.o func5.o
LIBS = -lm
TESTINT = testInt
EXEC = final

# CODE FOR TESTING OF INTEGRATE

compTestgen: testgen.o $(FUNCS) answer3.o
	gcc $(CFLAGS) testgen.o $(FUNCS) answer3.o -o $(TESTINT)

testgen: compTestgen
	./$(TESTINT) test-func1 1.0 2.0 10000
	./$(TESTINT) test-func2 -1.0 3.0 10000
	./$(TESTINT) test-func3 0.8 2.9 10000





all: hw3.o func1.o func2.o func3.o func4.o func5.o answer3.o
	gcc $(CFLAGS) -o $(EXEC) hw3.o func1.o func2.o func3.o func4.o func5.o answer3.o 


testall: all
	mkdir -p outputs
	mkdir -p tests
	./$(EXEC) testcases/test1 outputs/output1.out 
	./$(EXEC) testcases/test2 outputs/output2.out 
	./$(EXEC) testcases/test3 outputs/output3.out 
	./$(EXEC) testcases/test4 outputs/output4.out 
	./$(EXEC) testcases/test5 outputs/output5.out 



%.o : %.c
	gcc $(CFLAGS) -DTEST_INTEGRATE -DRUN_INTEGRATE -c $<


clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f hw3 hw3.prof
	/bin/rm -f -r testdir




