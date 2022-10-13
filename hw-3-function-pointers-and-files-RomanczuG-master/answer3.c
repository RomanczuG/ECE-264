// ***
// *** You MUST modify this file.
// ***
#include <stdio.h>
#include <stdbool.h>
#include "hw3.h"
// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable particial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  
    double range = intrg->upperlimit - intrg->lowerlimit;
    double deltax = range / intrg->intervals;
    int repetition = 0;
    double integration = 0;
    while((intrg->lowerlimit + repetition * deltax) <= intrg->upperlimit)
    {
        integration += intrg -> func(intrg->lowerlimit + repetition * deltax) * deltax;
        repetition++;
    }

    intrg -> answer = integration;

}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading

  FILE * fptr = fopen(infilename, "r");


  // if fopen fails, return false

  if (fptr == NULL)
  {
    fprintf(stderr, "fopen reading fail\n");
    return false;
  }

  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  Integration intrg;

  if(fscanf(fptr, "%lf", &intrg.lowerlimit) != 1)
  {
    fclose(fptr);
    return false;
  }

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  if(fscanf(fptr, "%lf", &intrg.upperlimit) != 1)
  {
    fclose(fptr);
    return false;
  }
  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false


  if(fscanf(fptr, "%d", &intrg.intervals) != 1)
  {
    fclose(fptr);
    return false;
  }

  // close the input file

  fclose(fptr);

  // open the output file for writing
  // if fopen fails, return false


  FILE * fptr2= fopen(outfilename, "w");
  if (fptr2 == NULL)
  {
    fprintf(stderr, "fopen writing fail\n");
    return false;
  }

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5

  funcptr funcs[] = {func1, func2, func3, func4, func5};


  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf

  int size = sizeof(funcs)/sizeof(funcptr);

  int index = 0;

  for (index = 0; index < size; index++)
  {
    intrg.func = funcs[index];
    integrate(& intrg);
    double answer = intrg.answer;
    if(fprintf(fptr2, "%lf\n", answer) < 1)
    {
      fclose(fptr2);
      return false;
    }
  }

  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false

  // after going through all functions in funcs
  // close the output file



  fclose(fptr2);



  // if the function reaches here, return true


  return true;


}
#endif // RUN_INTEGRATE
