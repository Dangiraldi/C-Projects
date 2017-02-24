#include "List.h"
#include "Prof.h"
#include <iostream>

using namespace std;

List::List()
{
	head = tail = NULL;
}
List::List(Prof n)
{
	head=&n;
}
void List::Insert(Prof n)
{
	Prof *ptr=new Prof(n);
	
	ptr->next=NULL;
	if (head == NULL)
	{
		head = ptr;
		tail = head;
	}
	else if(head==tail)
	{
		tail=ptr;
		head->next=tail;
	}
	else
	{
		Prof *temp;
		temp=tail;
		temp->next=ptr;
		tail=temp->next;
	}
	
}
void List::Delete(Prof *n)
{
	Prof *ptr;
	if(!head)
		return;
	if (head->getName()==n->getName())
	{
		ptr=head->next;
		delete head;
		head=ptr;
	}
	else
	{
		Prof *prev=head;
		ptr=head->next;
		while(ptr!=NULL&&(ptr->getName()!=n->getName()))
		{
			prev=ptr;
			ptr=ptr->next;
		}
		if(ptr!=tail)
		{
			prev->next=ptr->next;
			delete ptr;
			ptr=0;
		}
		else
		{
			prev->next=NULL;
			delete tail;
			tail=prev;
		}
	}
}
void List::Sort()
{
	Prof *temphead = head;
	bool swapped=false;
	while(head)
	{
		temphead=head;
		swapped=false;
		while (temphead->next)
		{
			if (temphead->getLName()>temphead->next->getLName())
			{
				swapped=true;
				Prof *swap = temphead;
 				temphead = temphead->next;
				swap->next=temphead->next;
				temphead->next = swap;
				temphead = temphead->next;
			}
			else
			if((temphead->getLName()==temphead->next->getLName())&&(temphead->getFName()>temphead->next->getFName()))
			{
				swapped=true;
				Prof *swap = temphead;
 				temphead = temphead->next;
				swap->next=temphead->next;
				temphead->next = swap;
				temphead = temphead->next;
			}
			else 
				temphead=temphead->next;
		}
		if(swapped==false)
				break;
	}
	cout<<"Here is the sorted list: \n";
	Display();
}
void List::Search(Prof x)
{
	Prof *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->getName()==x.getName())
		{
			cout<<"Professor found: "<<x<<endl;
		}
		else
			temp=temp->next;
	}
}
void List::Display()
{
	Prof *temp;
	temp=head;
	while(temp!=NULL)
	{
		//cout<<temp<<endl;
		cout<<temp->getName()<<"\n"<<temp->getLoc()<<"\n"<<temp->getPhone()<<endl;
		temp=temp->next;
	}
}
List::~List()
{
	Prof *temp;
	temp=head;
	while(head!=NULL)
	{
		temp=head->next;
		delete head;
		head=temp;
	}
	cout<<"\nList has been deleted.\n";
}