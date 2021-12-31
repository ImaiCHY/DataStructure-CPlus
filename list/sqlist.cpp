//
// Created by ImaiLisa on 12/30/21.
// Defines the operation of the sequence list
//

#include "sqlist.h"
#include <iostream>
#define maxsize 100;

using  namespace std;

//test
//rename the function to 'main'
int sqlist_test()
{

    Sqlist sq;
    initList(sq);
    cout << insertElem(sq,0,8025) << endl;
    cout << sq.data[0] << endl;

    return 0;
};



