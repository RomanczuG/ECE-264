CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw14
OBJS = hw14.o sorted.o huffman.o
HDRS = huffman.h sorted.h
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose
INPUT_DIR = ./inputs
EXPECTED_DIR = ./expected

$(EXEC): $(OBJS) $(HDRS)
	$(GCC) $(OBJS) -o $(EXEC)

all: $(OBJS) $(HDRS)
	$(GCC) $(OBJS) -o $(EXEC)

testmemory: $(EXEC)
	$(foreach file, $(wildcard $(INPUT_DIR)/*), $(VALGRIND) --log-file=$(file).log ./$(EXEC) $(file) $(file)_sorted $(file)_huffman $(file)_header;)

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f log? ./outputs/*header ./outputs/*huffman ./outputs/*sorted
	/bin/rm -f log? ./inputs/*header ./inputs/*huffman ./inputs/*sorted ./inputs/*.log