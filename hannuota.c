//Auther: yifan zhu
// This is a hannuota problem exercise
//如果是一個圆盘直接从a移动到c
//否則
//先将 n-1 个圆盘从a借助c移动到b
//再将第n个圆盘從a移動到c
//再将 n−1 个圆盘从b借助a移动到c

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

void hannuota(int, char, char, char);

int main(void)
{
    int n;
    char a = 'a';
    char b = 'b';
    char c = 'c';


    printf("please input number of hannuota: ");
    scanf("%d", &n);

    hannuota(n, a,b,c);
    return 0;
}

void hannuota(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("put plate %d from %c move to %c\n", n, a, c);
    }
    else
    {
        hannuota(n-1, a, c, b);
        printf("put plate %d from %c move to %c\n", n, a, c);
        hannuota(n-1, b, a, c);
    }
}