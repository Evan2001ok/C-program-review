//auther: yifan zhu
//basic linked-list add some basic function

#include <stdio.h>
#include <malloc.h>// malloc()
#include <string.h>
#include <stdbool.h> // bool 
#include <stdlib.h>// exit(-1)

//定义结构体
typedef struct node
{
    int data;//data
    struct node * pnext;//linked-list pointer
}node, *pnode;


pnode linked_list_create(void); // need return a address so need use pnode(struct node*)
void linked_list_output(pnode phead); // need output linked-list data follow the order
bool is_empty(pnode phead); // check linked-list is empty of not by check next node of phead
int length_list(pnode phead); 
bool insert_list(pnode, int, int);// insert value to linked-list
bool delete_list(pnode, int, int*);// delete value of linked-list, the third value can output which value be deleted
void sort_list(pnode);

int main(void)
{
    pnode phead = NULL;
    phead = linked_list_create();//function will return a phead address = phead
    if (is_empty(phead))
        printf("linked-list is  empty\n");
    else
        printf("linked-list is not empty\n");
    sort_list(phead);
    length_list(phead);
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

bool is_empty(pnode phead)
{
    if (NULL == phead->pnext)
        return true;
    else
        return false;
}

int length_list(pnode phead)
{
    int i = 0;//counter
    pnode p = phead->pnext;
    while (p != NULL)
    {
        p = p->pnext;// p++
        i++;// i++
    }
    //printf("length of linked-list is : %d", i);
    return i;
}

void sort_list(pnode phead)// linked-list sort function
{
    int t,i,j;
    pnode p;
    pnode q;
    int len = length_list(phead);
    for (i = 0, p = phead->pnext; i < len-1; i++,p = p->pnext)
    {
        for (j = i + 1, q = p->pnext; j < len; j++, q = q->pnext)
        {
            if (p->data > q->data) // linked-list opposit sort or not
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
            
        }
        
    }
    return;
}