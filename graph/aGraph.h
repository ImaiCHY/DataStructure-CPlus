//
// Created by ImaiLisa on 1/10/22.
//

#ifndef DATASTRUCTURE_AGRAPH_H
#define DATASTRUCTURE_AGRAPH_H

#include <clocale>

#define maxSize 100

typedef struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
    int info;
}ArcNode;

typedef struct
{
    char data;
    ArcNode *firtstarc;
}VNode;

typedef struct
{
    VNode adjlist[maxSize];
    int n,e;
}AGraph;

//
void Visit(int v)
{
    return;
}

int visit[maxSize];
void DFS(AGraph *G,int v)
{
    ArcNode *p;
    visit[v]=1;
    Visit(v);
    p=G->adjlist[v].firtstarc;
    while(p!=NULL)
    {
        if(visit[p->adjvex]==0)
            DFS(G,p->adjvex);
        p=p->nextarc;
    }

}

//
void BFS(AGraph *G,int v,int visit[maxSize])
{
    ArcNode *p;
    int que[maxSize],front=0,rear=0;
    int j;
    Visit(v);
    visit[v]=1;
    rear=(rear+1)%maxSize;
    que[rear]=v;
    while(front!=rear)
    {
        front=(front+1)%maxSize;
        j=que[front];
        p=G->adjlist[j].firtstarc;
        while(p!=NULL)
        {
            if(visit[p->adjvex]==0)
            {
                Visit(p->adjvex);
                visit[p->adjvex]=1;
                rear=(rear+1)%maxSize;
                que[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
}
#endif //DATASTRUCTURE_AGRAPH_H
