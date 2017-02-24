#ifndef PROF_H
#define PROF_H

#include <string>
using namespace std;

class Prof
{
	friend ostream& operator<<(ostream&,Prof&);
	friend istream& operator>>(istream&,Prof&);
public:
		Prof();
		Prof(Prof*);
		Prof(char[],char[],char[],char[]);
		void setName(char[],char[]);
		void setLoc(char[]);
		void setPhone(char[]);
		string getFName();
		string getLName();
		string getName();
		string getLoc();
		string getPhone();
		Prof *next;
		~Prof();
private:
		string fname;
		string lname;
		string location;
		string phone;
};
#endif