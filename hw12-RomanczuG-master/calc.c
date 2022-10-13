#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countNumberOfCharacters(FILE * fptr) 
{
  int numChar = 0;
  char onechar = fgetc(fptr);
  while (onechar != EOF)
    {
        onechar = fgetc(fptr);
        numChar++;
    }
  return numChar;
}

Stack * buildStack() {
	Stack * retval = malloc(sizeof(Stack));
    retval->head = NULL;
	return retval;
}

Node * buildNode(float value) {
	Node * node = malloc(sizeof(Node));
	node->value = value;
	node->next = NULL;
	return node;
}

void freeNode(Node * p, Stack * stack) {
    Node * element = stack ->head;
    if(element->next == NULL)
    {
        stack->head = NULL;
        free(p);
        return;
    }
    else
    {
        while(element ->next != p)
        {
            element = element->next;
        }
        p->next = NULL;
        element->next = NULL;
        free(p);
        return;
    }
}

void destroyStack(Stack * stack)
{
    Node * element = stack ->head;
    if(element->next == NULL)
    {
        stack->head = NULL;
        free(element);
        return;
    }
    else
    {
        while(element ->next != NULL)
        {
            element = element->next;
        }
        freeNode(element, stack);
        destroyStack(stack);
        return;
    }
}

void push(float number, Stack * stack)
{
    Node * element = stack ->head;
    Node * node = buildNode(number);
    
    if(element == NULL)
    {
        stack->head = node;
        return;
    }

    while(element->next != NULL)
    {
        element = element->next;
    }
    element->next = node;
    return;
}
float pop(Stack * stack)
{
    Node * element = stack ->head;
    float value;
    if(element->next == NULL)
    {
        value = element->value;
        freeNode(element,stack);
    }
    else
    {
        while(element->next != NULL)
        {
            element = element->next;
        }
        value = element->value;
        freeNode(element,stack);
    }
    return value;
}
float calculate(float value1, float value2, char sign)
{
    if(sign == '+')
    {
        return value2 + value1;
    }
    else if(sign == '-')
    {
        return value2 - value1;
    }
    else if(sign == '/')
    {
        return value2 / value1;
    }
    else if(sign == '*')
    {
        return value2 * value1;
    }
    else
    {
        return EXIT_FAILURE;
    }
}

bool performCalculations(char * operations, int length, float * result)
{
    Stack * stack = buildStack();
    int index = 0;
    for(index = 0; index<length; index++)
    {
        if(operations[index] != ' ')
        {
            if(operations[index] == '+' || operations[index] == '-' || operations[index] == '/' || operations[index] == '*')
            {
                if(operations[index+1] == ' ' || operations[index+1] == '\0')
                {
                    if(stack->head->next == NULL)
                    {
                        destroyStack(stack);
                        free(stack->head);
                        free(stack);
                        return false;
                    }
                    float value1 = pop(stack);
                    float value2 = pop(stack);
                    push(calculate(value1, value2, operations[index]), stack);
                }
                else
                {
                    int lengthNum = 1;
                    int temp = index + 1;
                    while(!(operations[temp] == '+' || operations[temp] == '-' || operations[temp] == '/' || operations[temp] == '*' || operations[temp] == ' '))
                    {
                        lengthNum++;
                        temp++;
                    }
                    char * value = malloc(sizeof(char) * length);
                    for(int index2 = 0; index2 < lengthNum; index2++)
                    {   
                        value[index2] = operations[index];
                        index++;
                    }
                    float number = (float) atof(value);
                    free(value);
                    push(number, stack);
                }
            }
            else
            {  
                int lengthNum = 0;
                int temp = index;
                while(!(operations[temp] == '+' || operations[temp] == '-' || operations[temp] == '/' || operations[temp] == '*' || operations[temp] == ' '))
                {
                    lengthNum++;
                    temp++;
                }
                char * value = malloc(sizeof(char) * length);
                for(int index2 = 0; index2 < lengthNum; index2++)
                {
                    value[index2] = operations[index];
                    index++;
                }
                float number = (float) atof(value);
                if(number == 0){
                    if(!(strcmp(value,"0") == 0 || strcmp(value,"-0") == 0))
                    {
                        
                        return false;
                    }
                }
                free(value);
                push(number, stack);
            }
        }
    }
    if(stack->head->next == NULL)
    {
        * result = stack->head->value;
        free(stack->head);
        free(stack);
        return true;
    }
    else
    {
        destroyStack(stack);
        free(stack);
        return false;
    }
}
