//Auther: yifan zhu
// this is a binary tree, function implement use different order of a binary tree output

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct btnode // binary tree use pointer implement
{
    int data;
    struct btnode * plchild; // left pointer child
    struct btnode * prchild; // right pointer child
};

struct btnode * create_btree(void);

void pre_bt_output(struct btnode * pt);
void in_bt_output(struct btnode * pt);
void post_bt_output(struct btnode * pt);

int main(void)
{
    struct btnode * pt = create_btree();
    
    pre_bt_output(pt);// 先序 // 中左右

    printf("\n");

    in_bt_output(pt); // 中序 // 左中右

    printf("\n");

    post_bt_output(pt); // 后序 // 左右中

    return 0;
}

struct btnode * create_btree(void)
{
    struct btnode * pa = (struct btnode *)malloc(sizeof(struct btnode));
    struct btnode * pb = (struct btnode *)malloc(sizeof(struct btnode));
    struct btnode * pc = (struct btnode *)malloc(sizeof(struct btnode));
    struct btnode * pd = (struct btnode *)malloc(sizeof(struct btnode));
    struct btnode * pe = (struct btnode *)malloc(sizeof(struct btnode));

    pa->data = 'a';
    pb->data = 'b';
    pc->data = 'c';
    pd->data = 'd';
    pe->data = 'e';

    pa->plchild = pb;
    pa->prchild = pc;
    pb->plchild = pb->prchild = NULL;
    pc->plchild = pd;
    pc->prchild = NULL;
    pd->plchild = NULL;
    pd->prchild = pe;
    pe->plchild = pe->prchild = NULL;

    return pa;
}

void pre_bt_output(struct btnode * pt)
{
    if (NULL != pt)
    {
        printf("%c ",pt->data);
        if (NULL != pt->plchild)
        {
            pre_bt_output(pt->plchild);
        }
        if (NULL != pt->prchild)
        {
            pre_bt_output(pt->prchild);
        }
    }
    
}

void in_bt_output(struct btnode * pt)
{
    if (NULL != pt)
    {
        if (NULL != pt->plchild)
        {
            in_bt_output(pt->plchild);
        }

        printf("%c ",pt->data);

        if (NULL != pt->prchild)
        {
            in_bt_output(pt->prchild);
        }
    }
    
}

void post_bt_output(struct btnode * pt)
{
    if (NULL != pt)
    {
        if (NULL != pt->plchild)
        {
            post_bt_output(pt->plchild);
        }
        if (NULL != pt->prchild)
        {
            post_bt_output(pt->prchild);
        }

        printf("%c ",pt->data);
    }
    
}