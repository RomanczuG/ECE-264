#include "hw2.h"
#include <stdio.h>
double integrate1(Range rng)
{
    /* Fill in for Part 1 */  
    double range = rng.upperlimit-rng.lowerlimit;
    double deltax = range / rng.intervals;
    int repetition = 0;
    double integration = 0;
    while((rng.lowerlimit + repetition *deltax) <= rng.upperlimit)
    {
        integration += func(rng.lowerlimit + repetition * deltax) * deltax;
        repetition++;
    }

    return integration;
}

void integrate2(RangeAnswer * rngans)
{
    rngans->answer = integrate1(rngans -> rng);
    printf("%f", rngans->answer);
    /* Fill in for Part 2 */

}
