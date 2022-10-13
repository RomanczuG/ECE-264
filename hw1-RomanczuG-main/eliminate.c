// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
	
  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]
	
  // initialize all elements
  for(int i = 0; i < n; i++)
  {
    arr[i] = i + 1; 
  }
  int eliminate = 1;
  int index = 0;
  int amountOfEliminated = 0;
  // counting to k,
  while (amountOfEliminated < n)
  {
    if(arr[index] == n+1)
    {
      index++;
    }
    else if (eliminate == k)
    {
      arr[index] = n+1;
      printf("%d\n", index);
      
      eliminate = 1;
      index++;
      amountOfEliminated++;

    }
    else
    {
      eliminate++;
      index++;
    }
    if (index == n)
    {
      index = 0;
    }
  }
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
