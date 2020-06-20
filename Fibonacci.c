#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Fibonacci.h"
HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q);
HugeInteger *hugeDestroyer(HugeInteger *p);
HugeInteger *parseString(char *str);
HugeInteger *parseInt(unsigned int n);
unsigned int *toUnsignedInt(HugeInteger *p);
HugeInteger *fib(int n);

//Max Saunders
//ID: 3772
//Data Structures

double difficultyRating(void){
    return 5;// mainly 1 error that required a friends help
};
double hoursSpent(void){
    return 20;//
};


HugeInteger *hugeAdd(HugeInteger *p, HugeInteger *q)
{
    int i, a, b;
    HugeInteger *limit;

    if(p == NULL || q == NULL || p->digits == NULL || q->digits == NULL)
        return NULL;

    limit = calloc(1, sizeof(HugeInteger));

    if(limit == NULL)
        return NULL;

    limit->length = (p->length > q->length) ? p->length : q->length;
    limit->digits = calloc(limit->length+1, sizeof(int));

    if(limit->digits == NULL)
    {
        free(limit);
        return NULL;
    }

    for(i = 0; i < limit->length; i++)
    {
        if(p->length <= i && q->length <= i)
            break;

        a = (i < p->length) ? p->digits[i] : 0;
        b = (i < q->length) ? q->digits[i] : 0;
        limit->digits[i] += (a+b);


        if(limit->digits[i] > 9)
        {
            limit->digits[i+1] += 1;
            if(i == limit->length-1)
                limit->length += 1;
        }

        limit->digits[i] %= 10;
    }

    return limit;
}

HugeInteger *hugeDestroyer(HugeInteger *p)
{
    if(p == NULL)
        return NULL;

    if(p->digits == NULL)
    {
        free(p->digits);
        return NULL;
    }
    free(p->digits);
    free(p);
    return NULL;
}

HugeInteger *parseString(char *str)
{
    int i, a, j = 0;
    HugeInteger *hugeInt;

    if(str == NULL)
        return NULL;

    hugeInt = malloc(sizeof(HugeInteger));

    if (hugeInt == NULL)
            return NULL;

    if(str != "")
    {
    	hugeInt->digits = calloc(strlen(str), sizeof(int));

    	if(hugeInt->digits == NULL)
	    {
	        free(hugeInt);
	        return NULL;
	    }
        hugeInt->length = strlen(str);

        for(i = hugeInt->length-1; i >= 0; i--)
        {
            a = str[i] - '0';
            hugeInt->digits[j] = a;
            j++;
        }
    }
    else
    {
        hugeInt->length = 1;
        hugeInt->digits = calloc(hugeInt->length, sizeof(int));

        if(hugeInt->digits == NULL)
	    {
	        free(hugeInt);
	        return NULL;
	    }
        hugeInt->digits[0] = 0;
    }

    return hugeInt;
}

HugeInteger *parseInt(unsigned int n)
{
    HugeInteger *hugeInt;
    unsigned int temp = n;
    int i, j = 0;

    hugeInt = malloc(sizeof(HugeInteger));

    if(hugeInt == NULL)
        return NULL;

    hugeInt->length = 1;

    // length of the number
    while(temp >= 10)
    {
        hugeInt->length += 1;
        temp = temp/10;
    }

    hugeInt->digits = calloc(hugeInt->length, sizeof(int));

    if(hugeInt->digits == NULL){
        free(hugeInt);
        return NULL;
    }

    for (i = hugeInt->length-1; i >= 0; i--)
    {
        hugeInt->digits[j] = (n == 0) ? 0 : n % 10;
        n = n / 10;
        j++;
    }

    return hugeInt;
}

// Calculates nth  term of the Fibonacci sequence
HugeInteger *fib(int n)
{
    int i;
    HugeInteger *Fn, **ints;


    if(n == 0 || n == 1)
        return parseInt(n);
    if(n == 2)
        return parseInt(1);

    ints = malloc(sizeof(HugeInteger*) * n);
    ints[0] = parseInt(0);
    ints[1] = parseInt(1);

    for(i = 2; i < n; i++)
    {
        ints[i] = hugeAdd(ints[i-1], ints[i-2]);
        hugeDestroyer(ints[i-2]);
    }

    //  nth term
    Fn = hugeAdd(ints[i-1], ints[i-2]);
    hugeDestroyer(ints[i-1]);
    hugeDestroyer(ints[i-2]);
    free(ints);

    return Fn;
}

// Converts HugeInteger to unsigned int
unsigned int *toUnsignedInt(HugeInteger *p)
{
    int i;
    unsigned int *num;
    HugeInteger *max_unsigned;

    if(p == NULL || p->digits == NULL || p->length > 10)
        return NULL;

    max_unsigned = parseInt(UINT_MAX);
    if(max_unsigned == NULL)
        return NULL;

    if(p->length == 10)
        for(i = 9; i >= 0; i--)
        {
            if(p->digits[i] <= max_unsigned->digits[i])
                break;
            else
                return hugeDestroyer(max_unsigned);
        }

    num = calloc(1, sizeof(unsigned int));


    for(i = p->length-1; i >= 0 ; i--)
        *num = *num*10 + p->digits[i];

    hugeDestroyer(max_unsigned);
    return num;
}





