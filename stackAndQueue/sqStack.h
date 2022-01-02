//
// Created by ImaiLisa on 1/1/22.
//

#ifndef DATASTRUCTURE_SQSTACK_H
#define DATASTRUCTURE_SQSTACK_H

#define maxSize 100

typedef struct
{
    int data [maxSize];
    int top;

}SqStack;

class sqStack{
public:
    void initStack(SqStack &st);
    int isEmppty(SqStack st);
    int push(SqStack &st,int x);
    int pop(SqStack &st,int &x);

};

//
void initStack(SqStack &st)
{
    st.top=-1;
}

//
int isEmppty(SqStack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
};

//
int push(SqStack &st,int x)
{
    if(st.top==maxSize-1)
        return 0;
    ++(st.top);
    st.data[st.top]=x;
    return 1;
}

//
int pop(SqStack &st,int &x)
{
    if(st.top==-1)
        return 0;
    x=st.data[st.top];
    --(st.top);
    return 1;
}
#endif //DATASTRUCTURE_SQSTACK_H
