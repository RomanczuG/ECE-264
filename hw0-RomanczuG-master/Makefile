#DEBUG = -DASCENDING
GCC=gcc #$(CFLAGS) $(DEBUG)
CFLAGS=-std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
EXEC = sort

# comment, not //
# target: dependance
# (tab) action
# -o name of output file
all: main.c sort.c
	$(GCC) $(CFLAGS) -o $(EXEC) main.c sort.c

ascending: main.c sort.c
	$(GCC) $(CFLAGS) -o $(EXEC) main.c sort.c -DASCENDING

#add ascending target here
	
test: all #rebuild the program if necessary "all", without this dependance, you will not rebuild even if you have changed soemthing
	./$(EXEC) testcases/inp1 
	./$(EXEC) testcases/inp2
	./$(EXEC) testcases/inp3	
# ./ current directory, you should not have ./ in your executable search path. this is security risk

test-ascending: ascending
	./$(EXEC) testcases/inp1
	./$(EXEC) testcases/inp2
	./$(EXEC) testcases/inp3	
	
clean:
	rm -f $(EXEC)
	rm -f *.o