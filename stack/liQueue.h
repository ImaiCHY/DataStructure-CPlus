//
// Created by ImaiLisa on 1/2/22.
//

#ifndef DATASTRUCTURE_LIQUEUE_H
#define DATASTRUCTURE_LIQUEUE_H

#include <malloc.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
};

typedef struct
{
    QNode *front;
    QNode *rear;
}LiQueue;

class liQueue{
public:
    void initQueue(LiQueue *&lqu);
    int isQueueEmpty(LiQueue *lqu);
    void enQueue(LiQueue *lqu,int x);
    int deQueue(LiQueue *lqu,int &x);

};

//
void initQueue(LiQueue *&lqu)
{
    lqu=(LiQueue *)malloc(sizeof (LiQueue));
    lqu->front=lqu->rear=NULL;
}

//
int isQueueEmpty(LiQueue *lqu)
{
    if(lqu->rear==NULL || lqu->front==NULL)
        return 1;
    else
        return 0;

}

//
void enQueue(LiQueue *lqu,int x)
{
    QNode *p;
    p=(QNode *)malloc(sizeof (QNode));
    p->data=x;
    p->next=NULL;
    if(lqu->rear==NULL)
        lqu->front=lqu->rear=p;
    else
    {
        lqu->rear->next = p ;
        lqu->rear=p;

    }
}

//
int deQueue(LiQueue *lqu,int &x)
{
    QNode *p;
    if(lqu->rear==NULL)
        return 0;
    else
        p=lqu->front;
    if(lqu->front==lqu->rear)
        lqu->front==lqu->rear=NULL;
    else
        lqu->front=lqu->front->next;
    x=p->data;
    free(p);
    return 1;
}
#endif //DATASTRUCTURE_LIQUEUE_H
