//
// Created by ImaiLisa on 1/4/22.
//

#ifndef DATASTRUCTURE_MATRICE_H
#define DATASTRUCTURE_MATRICE_H

#define maxSize 100
//int A[m][n]

class matrice{
public:
    void trsmat(int A[][maxSize],int B[][maxSize],int m,int n);
    void addmat(int C[][maxSize],int A[][maxSize],int B[][maxSize],int m,int n);
    void mutmat(int C[][maxSize],int A[][maxSize],int B[][maxSize],int m,int n,int k);
};

//
void trsmat(int A[][maxSize],int B[][maxSize],int m,int n)
{
    for(int i=0;i<m;++i)
        for(int j=0;j<0;++j)
            B[j][i]=A[i][j];
}

//
void addmat(int C[][maxSize],int A[][maxSize],int B[][maxSize],int m,int n)
{
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            C[i][j]=A[i][j]+B[i][j];
}

//
void mutmat(int C[][maxSize],int A[][maxSize],int B[][maxSize],int m,int n,int k)
{
    for(int i=0;i<m;++i)
        for(int j=0;j<k;j++)
        {
            C[i][j]=0;
            for(int h=0;h<n;++h)
                C[i][j]+=A[i][h]*B[h][j];
        }
}
#endif //DATASTRUCTURE_MATRICE_H
