// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  FILE * fptr = fopen(filename, "r");

  if (fptr == NULL)
  {
    return -1;
  }
  int count = 0;

  fseek(fptr, 0, SEEK_SET);
  int ival;
  while (fscanf(fptr, "%d", &ival) == 1)
  {
    count ++;
  }
  fclose(fptr);

  return count;
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  FILE * fptr = fopen(filename, "r");

  if (fptr == NULL)
  {
    return false;
  }
  int count = 0;
  int index;
  for(index = 0; index < size; index++)
  {
    fscanf(fptr, "%d", &intArr[index]);
    count++;
  }

  if (count != size)
  {
    return false;
  }

  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  int * e1 = (int *) p1;
  int * e2 = (int *) p2;
  
  if (e1 == e2){
    return 0;
  }
  else if(e1 > e2){
    return 1;
  }
  else if (e1 < e2){
    return -1;
  }

  return 0;
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  FILE * fptr = fopen(filename, "w");
  if (fptr == NULL)
  {
    fprintf(stderr, "fopen fail\n");
    return false;
  }
  int index;
  for (index = 0; index < size; index ++)
  {
    fprintf(fptr, "%d\n", intArr[index]);
  }

  fclose(fptr);
  return true;
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true
}
#endif

