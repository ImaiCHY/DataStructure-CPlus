//
// Created by ImaiLisa on 1/1/22.
//

#ifndef DATASTRUCTURE_LINKEDSTACK_H
#define DATASTRUCTURE_LINKEDSTACK_H

#include <malloc.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

class linkedStack{
public:
    void initStack(LNode *&lst);
    int isEmpty(LNode *lst);
    void push(LNode *lst,int x);
    int pop(LNode *lst,int &x);
};

//
void initStack(LNode *&lst)
{
    lst=(LNode *)malloc(sizeof(LNode));
    lst->next=NULL;
}

//
int isEmpty(LNode *lst)
{
    if(lst->next==NULL)
        return 1;
    else
        return 0;
}

//
void push(LNode *lst,int x) {
    LNode *p;
    p = (LNode *) malloc(sizeof(LNode));
    p->next = NULL;

    p->data=x;
    p->next=lst->next;
    lst->next=p;
}

//
int pop(LNode *lst,int &x)
{
    LNode *p;
    if(lst->next==NULL)
        return 0;

     p=lst->next;
     x=p->data;
     lst->next=p->next;
     free(p);
     return 1;
}
#endif //DATASTRUCTURE_LINKEDSTACK_H
