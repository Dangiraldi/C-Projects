#include <iostream>
#include "Priority.h"
using namespace std;

Priority_Queue::Priority_Queue()
{
	front=NULL;
}
void Priority_Queue::insert(int item, int priority)
{
	node *tmp, *q;
	tmp = new node;
	tmp->info = item;
	tmp->priority = priority;
	if (front == NULL || priority < front->priority)
	{
		tmp->link = front;
        front = tmp;
    }
    else
    {
        q = front;
        while (q->link != NULL && q->link->priority <= priority)
            q=q->link;
        tmp->link = q->link;
        q->link = tmp;
    }
}
void Priority_Queue::del()
{
    node *tmp;
    if(front == NULL)
        cout<<"Queue Underflow\n";
    else
    {
        tmp = front;
        cout<<"Deleted item is: "<<tmp->info<<endl;
        front = front->link;
        free(tmp);
    }
}
void Priority_Queue::display()
{
    node *ptr;
    ptr = front;
    if (front == NULL)
        cout<<"Queue is empty\n";
    else
    {	cout<<"Queue is :\n";
        cout<<"Priority       Item\n";
        while(ptr != NULL)
        {
            cout<<ptr->priority<<"                 "<<ptr->info<<endl;
            ptr = ptr->link;
        }
    }
}