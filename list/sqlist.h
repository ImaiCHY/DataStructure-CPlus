//
// Created by ImaiLisa on 12/30/21.
// Sqlist
#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H

#define maxSize 100  //maxsize is 100

//Sequence list
typedef struct
{
    int data[maxSize];
    int length;
}Sqlist;

class sqlist {
public:
    int findElem (Sqlist L,int e);
    int insertElem(Sqlist &L,int p,int e);
    int deleteElem(Sqlist &L,int p,int &e);
    void initList(Sqlist &L);
    int getElem(Sqlist L,int p, int &e);

};

//Find and return the location of the first element equal with e
//If false, return -1
int findElem (Sqlist L,int e)
{
    int i;
    for (i=0;i<L.length;++i)
    {
        if(e==L.data[i])
        {
            return i;
        }
    }
    return -1;
}

//Insert the new element e at the position of p (0<=p<=length)
//If the p position is wrong, return 0
//------------------------------------------------------------
//If the insertion is successful,
//move P and the elements after P back one bit, and add 1 to the length of the sequence table
//return 1;
int insertElem(Sqlist &L,int p,int e)
{
    int i;
    if(p<0 || p>L.length || L.length== maxSize)
        return 0;
    for (i=L.length-1;i>=p;--i)
        L.data[i+1]=L.data[i];
    L.data[p]=e;
    ++(L.length);
    return 1;
}

//Delete the element at position p
//Failure returned 0
//Success returned 1, and the deletion value is assigned to e
int deleteElem(Sqlist &L,int p,int &e)
{
    int i;
    if(p<0 || p>L.length-1)
        return 0;
    e=L.data[p];
    for(i=0;i<L.length-1;++i)
        L.data[i]=L.data[i+1];
    --(L.length);
    return 1;
}

//init
void initList(Sqlist &L)
{
    L.length = 0;

}

//Returns the value of the element at position p, giving e
//Failed return 0, successful return 1
int getElem(Sqlist L,int p, int &e)
{
    if(p<0 || p>L.length-1)
        return 0;
    e=L.data[p];
    return 1;
}






#endif //DATASTRUCTURE_SQLIST_H
