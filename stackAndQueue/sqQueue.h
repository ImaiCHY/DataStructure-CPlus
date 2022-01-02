//
// Created by ImaiLisa on 1/2/22.
//

#ifndef DATASTRUCTURE_SQQUEUE_H
#define DATASTRUCTURE_SQQUEUE_H

#define maxSize 100

typedef struct SqQueue
{
    int data[maxSize];
    int front;
    int rear;
}SqQueue;

class sqQueue{
public:
    void initQueue(SqQueue &qu);
    int isQueueEmpty(SqQueue qu);
    int enQueue(SqQueue &qu,int x);
    int deQueue(SqQueue &qu,int &x);
};

//
void initQueue(SqQueue &qu)
{
    qu.front=qu.rear=0;
}

//
int isQueueEmpty(SqQueue qu)
{
    if(qu.front=qu.rear)
        return 1;
    else
        return 0;
}

//
int enQueue(SqQueue &qu,int x)
{
    if((qu.rear+1)%maxSize==qu.front)
        return 0;
    qu.rear=(qu.rear+1)%maxSize;
    qu.data[qu.rear]=x;
    return 1;
}

//
int deQueue(SqQueue &qu,int &x)
{
    if(qu.front==qu.rear)
        return 0;
    qu.front=(qu.front+1)%maxSize;
    x=qu.data[qu.front];
    return 1;
}

#endif //DATASTRUCTURE_SQQUEUE_H
