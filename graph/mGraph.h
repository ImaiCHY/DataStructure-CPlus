//
// Created by ImaiLisa on 1/10/22.
//

#ifndef DATASTRUCTURE_MGRAPH_H
#define DATASTRUCTURE_MGRAPH_H

#define maxSize 100
#define INF 99999

typedef struct
{
    int no;
    char info;
}VertexType;

typedef struct
{
    int edges[maxSize][maxSize];
    int n,e;
    VertexType vex[maxSize];

}MGraph;

void Prim(MGraph g,int v0,int &sum)
{
    int lowcost[maxSize],vset[maxSize],v;
    int i,j,k,min;

    v=v0;
    for(i=0;i<g.n;++i)
    {
        lowcost[i]=g.edges[v0][i];
        vset[i]=0;
    }
    vset[v0]=1;
    sum=0;
    for(i=0;i<g.n-1;++i)
    {
        min=INF;
        for(j=0;j<g.n;++j)
        {
            if(vset[j]==0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        }
        vset[k]=1;
        v=k;
        sum+=min;
        for(j=0;j<g.n;++j)
        {
            if(vset[j]==0&&g.edges[v][j]<lowcost[j])
                lowcost[j]=g.edges[v][j];
        }
    }
}

//
typedef struct
{
    int a,b;
    int w;
}Road;
int v[maxSize];
int getRoot(int a)
{
    while(a!=v[a])a=v[a];
    return a;
}
void sort(Road road[],int e)
{

}
void Kruskal(MGraph g,int &sum,Road road[])
{
    int i;
    int N,E,a,b;
    N=g.n;
    E=g.e;
    sum=0;
    for(int i=0;i<N;++i)
        v[i]=1;
    sort(road,E);
    for(i=0;i<E;++i)
    {
        a= getRoot(road[i].a);
        b= getRoot(road[i].b);
        if(a!=b)
        {
            v[a]=b;
            sum+=road[i].w;
        }
    }
}

//
void Dijkstra(MGraph g,int v,int dist[],int path[])
{
    int set[maxSize];
    int min,i,j,u;
    for(i=0;i<g.n;++i)
    {
        dist[i]=g.edges[v][i];
        set[i]=0;
        if(g.edges[v][i]<INF)
            path[i]=v;
        else
            path[i]=-1;
    }
    set[v]=1;
    path[v]=-1;
    for(i=0;i<g.n-1;++i)
    {
        min=INF;
        for(j=0;j<g.n;++j)
            if(set[j]==0&&dist[j]<min)
            {
                u=j;
                min=dist[j];
            }
        set[u]=1;
        for(j=0;j<g.n;++j)
        {
            if(set[j]==0&&dist[u]+g.edges[u][j]<dist[j])
            {
                dist[j]=dist[u]+g.edges[u][j];
                path[j]=u;
            }
        }
    }
}
#endif //DATASTRUCTURE_MGRAPH_H
