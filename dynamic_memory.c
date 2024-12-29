#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Arr
{
    int * pBase;
    int len;
    int cnt; //able element number
};

void init_arr(struct Arr * ar, int length); //input function
void show_arr(struct Arr * ar); //output function
bool append_arr(struct Arr * ar, int value);// add a value into array
bool insert_arr(struct Arr * ar, int pos, int value);//
bool delete_arr(struct Arr * ar, int neg, int *pval);
// int get();
bool is_empty(struct Arr * ar);//use cnt check array is empty or not
bool is_full(struct Arr * ar);//use cnt and length check array is full or not
void sort_arr(struct Arr * ar);
void inversion_arr(struct Arr * ar);

int main(void)
{
    int pval;
    struct Arr ar;
    init_arr(&ar, 5);// pass, ar is pointer value, can change it to modify struct 3 elements. 
    append_arr(&ar, 4);
    append_arr(&ar, 3);
    append_arr(&ar, 1);
    append_arr(&ar, 8);
    append_arr(&ar, 9);
    sort_arr(&ar);
    //inversion_arr(&ar);
    //insert_arr(&ar, 1, 88);
    //insert_arr(&ar,6, 99);
    // if(delete_arr(&ar, 2, &pval))
    // {
    //     printf("delete successful\n");
    //     printf("you deleted value is %d\n", pval);
    // }
    // else
    //     printf("delete unsuccessful");

    //  if(append_arr(&ar, 6))
    //      printf("append ok\n");
    //  else
    //      printf("append error\n");
    show_arr(&ar); //output and check correct or not
    
    return 0;
}

void init_arr(struct Arr * ar, int length)
{
    ar->pBase = (int *)malloc(sizeof(int) * length);
    if (NULL == ar->pBase)
    {
        printf("dynamic memory error");
        exit(-1);
    }
    else
    {
    ar->len = length;
    ar->cnt = 0;
    }
    return;
}

//output function
void show_arr(struct Arr * ar)
{
    if (is_empty(ar))
    {
        printf("array empty");
        printf("\n");
    }
    else
    {
        for (int i = 0; i < ar->cnt; i++)
        {
            printf("%d", ar->pBase[i]);
            printf("\n");
        }
        printf("%d, %d", ar->len, ar->cnt);
    }
    return;
}

bool is_empty(struct Arr * ar)
{
    if (ar->cnt == 0)
        return true;
    else    
        return false;
}


bool is_full(struct Arr * ar)
{
    if(ar->cnt == ar->len)
        return true;
    else
        return false;
}

bool append_arr(struct Arr * ar, int value)
{
    if(is_full(ar))//
    {
        return false;
    }
    else
    {
        ar->pBase[ar->cnt] = value;
        (ar->cnt)++;//cnt++
        return true;
    }
}

bool insert_arr(struct Arr * ar, int pos, int value)
{
    if(is_full(ar))//
    {
        return false;
    }
    if(pos < 1 || pos > ar->cnt+1)
    {
        return false;
    }
    for (int i = ar->cnt-1; i >= pos-1; --i)
    {
        ar->pBase[i+1] = ar->pBase[i]; 
    }
    ar->pBase[pos-1] = value;
    (ar->cnt)++;
    return true;
}

bool delete_arr(struct Arr * ar, int neg,int *pval)
{
    if(is_empty(ar))//
    {
        return false;
    }
    if(neg < 1 || neg > ar->cnt)
    {
        return false;
    }
    *pval = ar->pBase[neg-1];
    for (int i = neg - 1; i < ar->cnt - 1; i++) // 从删除位置开始，将后续元素往前移动
    {
        ar->pBase[i] = ar->pBase[i + 1];
    }

    (ar->cnt)--; // 减少数组计数
    return true;
}

void inversion_arr(struct Arr * ar)
{
    int  i = 0;
    int j = ar->cnt-1;
    while (i < j)
    {
        int temp = ar->pBase[i];
        ar->pBase[i] = ar->pBase[j];
        ar->pBase[j] = temp;
        i++;
        j--;
    }
    
}

void sort_arr(struct Arr * ar)//bubble sort
{
    for (int i = 0; i < ar->cnt-1; i++)
    {
        for (int j = 0; j < ar->cnt-1-i; j++)
        {
            if (ar->pBase[j] > ar->pBase[j + 1]) 
            {
                int temp = ar->pBase[j];
                ar->pBase[j] = ar->pBase[j + 1];
                ar->pBase[j + 1] = temp;
            }
        }   
    }
}