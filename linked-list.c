//author: yifan zhu
//这是一个指针链表练习，涉及如何创建一个链表和输出链表
//This is a linked-list practice,include functions of how create linked-list and how output linked-list

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, *PNODE;

PNODE create_list(void);
void traverse_list(pHead);
int main(void)
{
    PNODE pHead = NULL;//PNODE pHead = sturct Node * pHead
    pHead = create_list();
    traverse_list(pHead);// output linked-list

    return 0;
}

PNODE create_list(void)
{
    int len;
    int value;

    //create a head and tail then follow len create linked-list
    PNODE pHead = (PNODE)malloc(sizeof(PNODE));
    if (pHead == NULL)
    {
        printf("error:分配错误");
        exit(-1);
    }
    PNODE pTail = pHead;
    pHead->pNext = NULL;

    printf("please input length of linked-list: ");
    scanf("%d\n",&len);
    for (int i = 0; i < len; i++)
    {
        printf("please input %d of value\n", i+1);
        scanf("%d", &value);

        PNODE pNew = (PNODE)malloc(sizeof(PNODE));
        if (pNew == NULL)
        {
            printf("error:分配错误");
            exit(-1);
        }
        pNew->data = value;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    while (p != NULL)
    {
        printf("%d \n",p->data);
        p = p->pNext; //p++
    }
    
}
