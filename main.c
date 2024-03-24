#include <stdio.h>
#include <stdlib.h>

/*
our training data set
*/

float train[][3] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 9},
};

float rand_num(void)
{
    /* generating random number b/w 1 and 10 */
    return (float)rand() / (float)RAND_MAX;
};

// y = x * w --> x is the number

int main()
{
    // printf("hello world");
    float w = rand_num();
    printf("%f\n", w);
    return 0;
}
