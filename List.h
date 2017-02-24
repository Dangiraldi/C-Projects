#ifndef LIST_H
#define LIST_H

#include "Prof.h"

class List:public Prof
{
public:
	List();
	List(Prof);
	void Sort();
	void Insert(Prof);
	void Delete(Prof*);
	void Search(Prof);
	void Display();
	~List();
private:
	Prof *head;
	Prof *tail;
};
#endif