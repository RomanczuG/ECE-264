#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
		return EXIT_FAILURE;
	}

	float result; //store the result of your calculation here.
	
	FILE * fptr = fopen(argv[1], "r");

	if (fptr == NULL) {
		fprintf(stderr, "Could not open file for reading\n");
		return EXIT_FAILURE;
	}

	int size = countNumberOfCharacters(fptr);

	int rtv; // return value
  	rtv = fseek(fptr, 0, SEEK_SET);
  	if (rtv == -1) // fseek fails
    {
      fclose (fptr);
      return EXIT_FAILURE;
    }
	
	char * operation = malloc(sizeof(char) * (size + 1));

	if(size == 0)
	{
		return EXIT_FAILURE;
	}

	for(int index = 0; index < size; index++)
	{
		operation[index] = fgetc(fptr);
	}
	operation[size] = '\0';

//	printf("Operation is %s \n", operation);

	fclose(fptr);

	if(performCalculations(operation, size, &result))
	{
		printf("%f\n", result);
		free(operation);
	}
	else
	{
		free(operation);
		return EXIT_FAILURE;
	}
	/* Insert code here to perform the RPN calculation.
	Don't forget to free any memory you allocate once you're done with it! */

	
	
	return EXIT_SUCCESS;
}
