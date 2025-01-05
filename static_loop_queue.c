//Auther: yifan zhu
// This is a queue program, implement a easy static loop queue.
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

typedef struct queue // 隊列
{
    int * pbase; // store all data
    int front;
    int rear;
}queue;

void init(queue *); // init program,
bool en_queue(queue *, int);// 入隊// check can input value into queue or not
bool out_queue(queue *, int*);//出隊 //out value of queue
void output(queue *);
bool full_queue(queue *);
bool empty_queue(queue *);

int main(void)
{
    queue q;//create a queue
    int value;
    init(&q);
    en_queue(&q, 1);
    en_queue(&q, 2);
    en_queue(&q, 3);
    en_queue(&q, 4);
    en_queue(&q, 5);
    if (out_queue(&q, &value))
    {
        printf("out queue successful, value is %d\n", value);
    }
    else
    {
        printf("out queue uncessful");
    }
    en_queue(&q, 8);
    output(&q);
    return 0;
}

void init(queue * q)
{
    q->pbase = (int*)malloc(sizeof(int)*6); // create a queue have 6 int length 
    q->front = 0;// init front
    q->rear = 0; // init rear
}

bool en_queue(queue *q, int value)
{
    if (full_queue(q))
        return false;
    else
    {
        q->pbase[q->rear] = value;// 入隊is put value into queue 's rear location
        q->rear = (q->rear + 1)%6; // rear = (rear+1)%length of array 
        return true;
    }
    
}

bool full_queue(queue * q)
{
    if ((q->rear + 1)%6 == q->front)// f == (r+1)%length 
    {
        return true;
    }
    else
    {
        return false;
    }
}

void output(queue *q)
{
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d\n", q->pbase[i]);
        i = (i+1)%6;
    }
    return;   
}

bool out_queue(queue * q, int* value)
{
    if (empty_queue(q))
    {
        return false;
    }
    else
    {   
        *value = q->pbase[q->front];//value back shows that which value out of queue
        q->front = (q->front + 1)%6; // f = (f+1)%length of array 
        return true;
    }
}

bool empty_queue(queue * q)
{
    if (q->front == q->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}