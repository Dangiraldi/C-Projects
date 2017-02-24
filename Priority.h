#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>
#include "Node.h"
using namespace std;

class Priority_Queue: public node
{
public:
    Priority_Queue();
    void insert(int,int);
    void del();
    void display();
protected:
    node *front;
};

#endif