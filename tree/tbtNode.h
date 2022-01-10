//
// Created by ImaiLisa on 1/10/22.
//

#ifndef DATASTRUCTURE_TBTNODE_H
#define DATASTRUCTURE_TBTNODE_H

#include <clocale>

typedef struct TBTNode
{
    char data;
    int ltag,rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;

//
void visit(TBTNode *p)
{
    return;
}

//
void InThread(TBTNode *p,TBTNode *&pre)
{
    if(p!=NULL)
    {
        InThread(p->lchild,pre);
        if(p->lchild=NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        p=p->rchild;
        InThread(p,pre);
    }
}

//
void createInThread(TBTNode *root)
{
    TBTNode *pre =NULL;
    if(root!=NULL)
    {
        InThread(root,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

//
TBTNode *First(TBTNode *p)
{
    while(p->ltag==0)
        p=p->lchild;
    return p;
}

//
TBTNode *Next(TBTNode *p)
{
    if(p->rtag==0)
        return First(p->rchild);
    else
        return p->rchild;
}

//
void InOrder(TBTNode *root)
{
    for(TBTNode *p= First(root);p!= NULL;p= Next(p))
        visit(p);
}

void preThread(TBTNode *p,TBTNode *&pre)
{
    if(p!=NULL)
    {
        if(p->lchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL && pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        if(p->ltag==0)
            preThread(p->lchild,pre);
        if(p->rtag==0)
            preThread(p->rchild,pre);
    }
}

//
void preOrder(TBTNode *root)
{
    if(root!=NULL)
    {
        TBTNode *p=root;
        while(p!=NULL)
        {
            while(p->ltag==0)
            {
                visit(p);
                p=p->lchild;
            }
            visit(p);
            p=p->rchild;
        }
    }
}

//
void postThread(TBTNode *p,TBTNode *&pre)
{
    if(p!=NULL)
    {
        postThread(p->lchild,pre);
        postThread(p->rchild,pre);
        if(p->lchild==NULL)
        {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL && pre->rchild==NULL)
        {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
    }
}
#endif //DATASTRUCTURE_TBTNODE_H
