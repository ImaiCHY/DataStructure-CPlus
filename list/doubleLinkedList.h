//
// Created by ImaiLisa on 12/31/21.
//

#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H

#include <cstdlib>

typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;
class doubleLinkedList {
public:
    void createDListR(DLNode *&L,int a[],int n);
    DLNode* findNode(DLNode *C,int x);
    void insertNode(DLNode *&s,DLNode *p){s->next=p->next;s->prior=p;p->next=s;s->next->prior=s;};
    int deleteNode(DLNode *&p){DLNode *q=p->next;p->next=q->next;q->next->prior=p;free(q);};

};

//尾插法建立双链表
void createDListR(DLNode *&L,int a[],int n)
{
    DLNode *s,*r;
    int i;
    L=(DLNode*)malloc(sizeof(DLNode));
    L->prior=NULL;
    L->next=NULL;
    r=L;
    for(i-0;i<n;++i)
    {
        s=(DLNode*)malloc(sizeof(DLNode));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}

//Find the first node with the value of x in the double linked list C
//If successds,ruturn the node pointer;otherwise,return null
DLNode* findNode(DLNode *C,int x)
{
    DLNode *p=C->next;
    while(p!=NULL)
    {
        if(p->data==x)
            break;
        p=p->next;
    }
    return p;
}
#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
