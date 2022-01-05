//
// Created by ImaiLisa on 1/5/22.
//

#ifndef DATASTRUCTURE_BTNODE_H
#define DATASTRUCTURE_BTNODE_H

#include <clocale>
#include <iostream>

#define maxSize 100
using namespace std;

typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

class btNode{
public:
    void visit(BTNode *p);
    void preOrder(BTNode *p);
    void inOrder(BTNode *p);
    void postOrder(BTNode *p);
    int getDepth(BTNode *p);
    void search(BTNode *p,BTNode *&q,int key);
    void trave(BTNode *p,int k);
    void level(BTNode *p);
    void preOrderNonrecursion(BTNode *bt);
    void inOrderNonrecursion(BTNode *bt);
    void postOrderNonrecursion(BTNode *bt);

};

//
void visit(BTNode *pNode)
{};

//
void preOrder(BTNode *p)
{
    if(p!=NULL)
    {
        visit(p);

        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

//
void inOrder(BTNode *p)
{
    if(p!=NULL)
    {
        inOrder(p->lchild);
        visit(p);
        inOrder(p->rchild);
    }
}

//
void postOrder(BTNode *p)
{
    if(p!=NULL)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        visit(p);
    }
}

//
int getDepth(BTNode *p)
{
    int LD,RD;
    if(p=NULL)
        return 0;
    else
    {
        LD= getDepth(p->lchild);
        RD= getDepth(p->rchild);
        return(LD>RD?LD:RD)+1;
    }
}

//
void search(BTNode *p,BTNode *&q,int key)
{
    if(p!=NULL)
    {
        if(p->data==key)
            q=p;
        else
        {
            search(p->lchild,q,key);
            if(q==NULL)
                search(p->rchild,q,key);
        }
    }

}

//
void trave(BTNode *p,int k)
{
    int n=0;
    if(p!=NULL)
    {
        ++n;
        if(k==n)
        {
            cout<<p->data<<endl;
            return;

        }
        trave(p->lchild,k);
        trave(p->rchild,k);
    }
}

//
void level(BTNode *p)
{
    int front,rear;
    BTNode *que[maxSize];
    front=rear=0;
    BTNode *q;
    if(p!=NULL)
    {
        rear=(rear+1)%maxSize;
        que[rear]=p;
        while(front!=rear)
        {
            front=(front+1)%maxSize;
            q=que[front];
            visit(q);
            if(q->lchild!=NULL)
            {
                rear=(rear+1)%maxSize;
                que[rear]=q->lchild;
            }
            if(q->rchild!=NULL)
            {
                rear=(rear+1)%maxSize;
                que[rear]=q->rchild;
            }
        }
    }
}

//
void preOrderNonrecursion(BTNode *bt)
{
    if(bt!=NULL)
    {
        BTNode *Stack[maxSize];
        int top=-1;
        BTNode  *p;
        Stack[++top]=bt;
        while(top!=-1)
        {
            p=Stack[top--];
            visit(p);
            if(p->rchild!=NULL)
                Stack[++top]=p->rchild;
            if(p->rchild!=NULL)
                Stack[++top]=p->lchild;
        }
    }
}

//
void inOrderNonrecursion(BTNode *bt)
{
    if(bt!=NULL)
    {
        BTNode *Stack[maxSize];
        int top=-1;
        BTNode *p;
        p=bt;
        while(top!=-1 || p!=NULL)
        {
            while(p!=NULL)
            {
                Stack[++top]=p;
                p=p->lchild;
            }
            if(top!=-1)
            {
                p=Stack[top--];
                visit(p);
                p=p->rchild;
            }
        }
    }

}

//
void postOrderNonrecursion(BTNode *bt)
{
    BTNode *Stack1[maxSize],*Stack2[maxSize];
    int top1,top2; top1=top2=-1;
    BTNode *p=NULL;
    Stack1[++top1]=bt;
    while(top1 !=-1)
    {
        p=Stack1[top1--];
        Stack2[++top2]=p;
        if(p->rchild!=NULL)
            Stack1[++top1]=p->rchild;
        if(p->rchild!=NULL)
            Stack1[++top1]=p->lchild;
    }
    while(top2!=-1)
    {
        p=Stack2[top2--];
        visit(p);
    }
}
#endif //DATASTRUCTURE_BTNODE_H
