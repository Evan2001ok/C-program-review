//author: yifan zhu
//这是一个指针链表练习，涉及如何创建一个链表和输出链表
//This is a linked-list practice,include functions of how create linked-list and how output linked-list

#include <stdio.h>
#include <malloc.h>// malloc()
#include <string.h>
#include <stdlib.h>// exit(-1)

//定义结构体
typedef struct node
{
    int data;//data
    struct node * pnext;//linked-list pointer
}node, *pnode;

pnode linked_list_create(void); // need return a address so need use pnode(struct node*)
void linked_list_output(pnode phead); // need output linked-list data follow the order

int main(void)
{
    pnode phead = NULL;
    phead = linked_list_create();//function will return a phead address = phead
    linked_list_output(phead);
    return 0;
}

pnode linked_list_create(void)// create a linked_list need user input a list length
{
    int len;
    int value;

    //create phead of linked-list
    pnode phead = NULL;//initialize
    phead = (pnode)malloc(sizeof(node));
    if (phead == NULL)
    {
        printf("error,fail to append");
        exit(-1);
    }
    //create a tail of linked-list
    pnode ptail = phead;
    ptail->pnext = NULL;


    printf("please input a length of linked-list: ");
    scanf("%d",&len);
    for (int i = 0; i < len; i++)
    {
        printf("please input the %d time of value: ", i+1);// because nature number of times is i+1
        scanf("%d", &value);
        
        //create a pnew node
        //data strcture likes:     phead -> ptail -> pnew
        pnode pnew = (pnode)malloc(sizeof(pnode));
        if (pnew == NULL)
        {
            printf("error,fail to append");
            exit(-1);
        }
        //shows how append pnew node to linked-list
        pnew->data = value;
        ptail->pnext = pnew;
        pnew->pnext = NULL;
        ptail = pnew;
    }
    return phead;
}

void linked_list_output(pnode phead)
{
    pnode p = phead->pnext;
    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->pnext;// p++
    }
    
}
