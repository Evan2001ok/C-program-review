//auther: yifan zhu
// This is use a linked-list structure to create a stack,it can push/pop/clear stack
#include <stdio.h>
#include <malloc.h>// malloc()
#include <string.h>
#include <stdbool.h> // bool 
#include <stdlib.h>// exit(-1)

typedef struct node
{
    int data;// data part
    struct node * pnext; //pointer part 
}node,*pnode;

typedef struct stack
{
    pnode ptop;
    pnode pbottom;
}stack,*pstack;

void init_stack(pstack);//create a new stack, stack inside have ptop and pbottom.
void push_stack(pstack, int);//push a value into the stack
void output_stack(pstack);// output follow (input early output late)
bool pop_stack(pstack, int*);//pop a value from stack and display it
bool empty(pstack);
void clear(pstack);//clear all in stack (free all process of stack)

int main(void)
{
    stack s; // create a stack as s
    int val;// when pop ,display value

    init_stack(&s);//initial variable
    push_stack(&s, 1);//push variable into stack
    push_stack(&s, 2);
    push_stack(&s, 3);
    push_stack(&s, 4);
    output_stack(&s);

    //clear(&s);
    //output_stack(&s);
    if (pop_stack(&s, &val))
        printf("pop successful, pop value is: %d \n", val);
    else
        printf("pop unccessful!\n");

    output_stack(&s);//output stack
        
    return 0;
}

void init_stack(pstack ps)
{
    ps->ptop = (pnode)malloc(sizeof(node));
    if (NULL == ps->ptop)
    {
        printf("error, assign error");
        exit(-1);
    }
    else
    {
        ps->pbottom = ps->ptop;
        ps->ptop->pnext = NULL;// ps->pbottom->pnext = NULL also true
    }
        
}

void push_stack(pstack ps, int value)
{
    pnode pnew = (pnode)malloc(sizeof(node));
    if (pnew == NULL)
    {
        printf("error, assign error");
        exit(-1);
    }
    pnew->data = value;
    //core logic of push
    pnew->pnext = ps->ptop;// pnew poniter connect to ptop.
    ps->ptop = pnew;
}

void output_stack(pstack ps)
{
    pnode p = ps->ptop;
    while (p != ps->pbottom)
    {
        printf("%d\n", p->data);
        p = p->pnext;
    }
    return;
}

bool empty(pstack ps)
{
    if (ps->pbottom == ps->ptop)
        return true;
    else    
        return false;
}

bool pop_stack(pstack ps, int *val)
{
    if (empty(ps))
    {
        printf("stack is empty");
        return false;
    }
    else
    {
        pnode p = ps->ptop;
        *val = p->data;
        ps->ptop = p->pnext;
        free(p);
        p = NULL;
        return true;
    }
}

void clear(pstack ps)
{
    if (empty(ps))
    {
        return;
    }
    else
    {
        pnode p = ps->ptop;
        pnode q = NULL;
        while (p != ps->pbottom)
        {
            q = p->pnext;
            free(p);
            p = q;
        }
        ps->ptop = ps->pbottom;
    }
}