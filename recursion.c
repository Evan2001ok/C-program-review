//Auther: yifan zhu
// This is a recursion fuction, calculate sum of total of 100 = 1+2+3+...100
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

long sum(long n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return sum(n-1) + n;
    }
}

int main(void)
{
    printf("3 's total sum is: %d", sum(10));
    return 0;
}
