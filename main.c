#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// our training data set
// each element will contain two floating point nums
float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 9},
};

#define train_count (sizeof(train) / sizeof(train[0]))

// gonna generate random floating point numbers
float rand_float(void)
{
    // generating random number b/w 1 and 10
    return (float)rand() / (float)RAND_MAX;
};

// calculating the cost function
float cost_func(float w)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i)
    {
        // 0th position float num of every single element of the array
        float x = train[i][0];

        // 0th pos float num * the randomly generated num
        float y = x * w;

        // calculating the loss
        float d = y - train[i][1];

        // getting the absolute value (from my understanding for now)
        result += d * d;

        // printf("Actual: %f, Expected: %f\n", y, train[i][1]);
    }

    // avg of cost
    result /= train_count;
    return result;
};

int main()
{
    // y = x * w --> x is the input number, w is some sort of number

    // srand(seed rand) --> seeds the random num generator func, if we pass a fix value every time it will generate same static value but if we pass something changing/variable like time the function will generate different numbers.

    // srand(time(0));
    srand(69);
    float w = rand_float() * 10.0f;

    float eps = 1e-3; // 1*10^-3 = .001

    // implementing derivative's definition directly ?!? Nah just 'finite difference (approximation of derivatives)'
    float d_cost = (cost_func(w + eps) - cost_func(w)) / eps;
    printf("%f\n", d_cost);
    printf("%f\n", cost_func(w));
    w -= d_cost;
    printf("%f\n", cost_func(w));

    /*  printf("%f\n", cost_func(w));
     printf("%f\n", cost_func(w - eps));
     printf("%f\n", cost_func(w - eps * 2)); */

    return 0;
}
