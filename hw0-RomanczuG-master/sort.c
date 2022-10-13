#include "sort.h"


void ssort(int * arr, int size) {
	// indexes needed for searching
	int index = 0;
	int searchIndex = 0;
	int savedIndex = 0;
	// temporary value neccesary for the swap
	int temp = 0;
	// loop that goes through the array
	for(index = 0; index<size; index++)
	{
		// values necesary for the next search
		searchIndex = index;
		savedIndex = index;
		// searching
		while(searchIndex < size)
		{	
			// finding
			#ifdef ASCENDING
			if(arr[savedIndex] > arr[searchIndex])
			#else
			if(arr[savedIndex] < arr[searchIndex])
			#endif
			{
				savedIndex = searchIndex;
			}
			searchIndex++;
		}
		// swapping values
		temp = arr[index];
		arr[index] = arr[savedIndex];
		arr[savedIndex] = temp;
	}

	/* For step 3, fill this in to perform a selection sort
	   For step 4, add conditional compilation flags to perform an ascending selection sort instead */
}

