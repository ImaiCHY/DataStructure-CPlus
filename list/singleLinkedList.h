//
// Created by ImaiLisa on 12/31/21.
//

#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H

#include <clocale>
#include <cstdlib>

#define maxSize 100



//Single linked list
//Unless otherwise specified, the following linked lists contain header nodes
typedef struct LNode
{
    int data;
    LNode *next;
}LNode;

class singleLinkedList{
public:
    void increasingMerge(LNode *A,LNode *B,LNode *&C);
    void decreasingMerge(LNode *A,LNode *B,LNode *&C);
    void createListR(LNode *&C,int a[],int n);
    void createListF(LNode *&C,int a[],int n);
    void insertNode(LNode *&s,LNode *p){s->next=p->next;p->next=s;};
    int deleteNode(LNode *&p){LNode *q=p->next;int a=q->data; p->next=p->next->next;free(q);return a;};
    int findAndDelete(LNode *C,int x);
};

//A. B is the element increasing single linked list
//The result is in single linked list C(also increasing)
void increasingMerge(LNode *A,LNode *B,LNode *&C)
{
    LNode *p=A->next;
    LNode *q=B->next;
    LNode *r;
    C=A;
    C->next=NULL;
    free(B);
    r=C;
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<=q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else
        {
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    r->next=NULL;
    if(p!=NULL)
        r->next=p;
    if(q!=NULL)
        r->next=q;
}

//A. B is the element decreasing single linked list
//The result is in single linked list C (also decreasing)
void decreasingMerge(LNode *A,LNode *B,LNode *&C)
{
    LNode *p=A->next;
    LNode *q=B->next;
    LNode *s;
    C=A;
    C->next=NULL;
    free(B);
    while(p!=NULL&&q!=NULL)
    {
        if(p->data<=q->data)
        {
            s=p;
            p=p->next;
            s->next=C->next;
            C->next=s;
        }
        else
        {
            s=q;
            q=q->next;
            s->next=C->next;
            C->next=s;
        }

    }
    while (p!=NULL)
    {
        s=p;
        p->next;
        s->next=C->next;
        C->next=s;
    }
    while(q!=NULL)
    {
        s=q;
        q=q->next;
        s->next=C->next;
        C->next=s;
    }
}

//尾插法将数组a中数据插入单链表C
void createListR(LNode *&C,int a[],int n)
{
    LNode *s,*r;
    int i;
    C=(LNode *)malloc(sizeof(LNode));
    C->next=NULL;
    r=C;
    for(i=0;i<n;++i)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;

}

//头插法将数组a中数据插入单链表C
void createListF(LNode *&C,int a[],int n)
{
    LNode *s;
    int i;
    C=(LNode*)malloc(sizeof(LNode));
    C->next=NULL;
    for (i=0;i<n;++i)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        s->next=C->next;
        C->next=s;
    }
}

//Find whether there is a node with the value of x and delete it
//1 is returned for success and 0 is returned for failure
int findAndDelete(LNode *C,int x)
{
    LNode *p,*q;
    p=C;
    while(p->next!=NULL)
    {
        if(p->next->data==x)
            break;
        p=p->next;
    }
    if(p->next==NULL)
        return 0;
    else
    {
        q=p->next;
        p->next=p->next->next;
        free(q);
        return 1;
    }
}
#endif //DATASTRUCTURE_SINGLELINKEDLIST_H
