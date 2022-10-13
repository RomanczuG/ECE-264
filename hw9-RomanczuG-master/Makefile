CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = 
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = program
OBJS =  maze.o mazehelper.o path.o solver.o hw9.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

$(EXEC): $(OBJS) maze.h mazehelper.h path.h solver.h
	$(GCC) $(OBJS) -o $(EXEC) 


test: $(EXEC)
	./$(EXEC)  inputs/maze1 path1 
	./$(EXEC)  inputs/maze2 path2 
	./$(EXEC)  inputs/maze3 path3 
	./$(EXEC)  inputs/maze4 path4 
	./$(EXEC)  inputs/maze5 path5 


testDiff: $(EXEC)
	diff -w output_3_1 expected/expected_3_1
memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) 4

%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f id? first? last? log?