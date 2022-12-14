#include "msort.h"
#include "student.h"
#include <stdio.h>

#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) {
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.
	
	//FILL IN
	
	if (nel <= 1) return;

	//Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces
		
	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array

	//FILL IN

	int midpoint = nel / 2;	
	//2a. Sort the first half of the array (remember to adjust the # elements)

	//FILL IN

	//msort(base, midpoint, compar);
	msort(base, nel/2, compar);

	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)

	//FILL IN
	
	//msort(&base[midpoint], ((nel + 1) / 2), compar);
  	msort(&base[nel/2], (nel + 1)/2, compar);

	//3a. Merge the two arrays (use merge)

	//FILL IN

	Student * mergedArray = merge(base, midpoint, &base[midpoint], ((nel + 1)/ 2), compar);
	
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you returned from merge -- you don't need it after the copy!

	//FILL IN

	copy(base, mergedArray, nel);
		
	return;
}
#endif

#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
	//1. Allocate space for the returned merged array
	
	//FILL IN

	Student * mergedArray = malloc(sizeof(Student) * (nel1 + nel2));
	
	//2. Create indices to keep track of where you are in the three arrays

	//FILL IN

	int indexBase1 = 0;
	int indexBase2 = 0;
	int index = 0;
	
	//3. Go through base1 and base2, and merge them into the returned array

	//FILL IN
	for(index = 0; index < (nel1 + nel2); index++)
	{
		if ((compar(&base1[indexBase1], &base2[indexBase2]) < 0 && indexBase1 != nel1) || indexBase2 == nel2)
		{
			mergedArray[index] = base1[indexBase1];
			indexBase1 ++;
		}
		else
		{
			mergedArray[index] = base2[indexBase2];
			indexBase2 ++;
		}
	}
	
	//4. Return the merged array

	//FILL IN

	return mergedArray;
}


void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
