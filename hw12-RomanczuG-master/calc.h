#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Linked list node
typedef struct Node {
	float value;
	struct Node * next;
} Node;

//Stack head
typedef struct Stack {
	Node * head;
} Stack;

Stack * buildStack();
Node * buildNode(float value);
void destroyStack(Stack * stack);

// Operations on stack
void push(float number, Stack * stack);
float pop(Stack * stack);


// Calculations
bool performCalculations(char * operations, int length, float * result);

float calculate(float value1, float value2, char sign);

int countNumberOfCharacters(FILE * fptr);
