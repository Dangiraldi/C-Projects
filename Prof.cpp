#include "Prof.h"
#include <string>
#include <iostream>

using namespace std;

Prof::Prof()
{

}
Prof::Prof(Prof *n)
{
	fname=n->fname;
	lname=n->lname;
	phone=n->phone;
	location=n->location;
}
Prof::Prof(char f[256],char l[256],char o[8],char p[13])
{
	setName(f,l);
	setLoc(o);
	setPhone(p);
}
void Prof::setName(char f[256],char l[256])
{
	string fname(f);
	string lname(l);
}
void Prof::setLoc(char l[8])
{
	string location(l);
}
void Prof::setPhone(char p[13])
{
	string phone(p);
}
string Prof::getName()
{
	return fname+' '+lname;
}
string Prof::getLoc()
{
	return location;
}
string Prof::getPhone()
{
	return phone;
}
string Prof::getFName()
{
	return fname;
}
string Prof::getLName()
{
	return lname;
}
ostream& operator<<(ostream& os,Prof& n)
{
	return os<<"\n"<<n.getName()<<"\n"<<n.getLoc()<<"\n"<<n.getPhone()<<endl;
	//return os;
}
istream& operator>>(istream& is,Prof& n)
{
	is>>n.fname>>n.lname>>n.location>>n.phone;
	return is;
}
Prof::~Prof()
{

}