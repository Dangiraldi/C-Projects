#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex{

public:
	Complex(); //Constructors
	Complex(int x);
	Complex operator+(const Complex& c);//Overloaded operators, including iostream
	Complex operator-(const Complex& c);
	Complex operator*(const Complex& c);
	Complex operator/(const Complex& c);
	friend ostream &operator<<(ostream&,const Complex&);
	friend istream &operator>>(istream&,const Complex&);
	void setVal(int);
	int getVal();
//private:
	int value; // Recieved error messages when I tried to input from main with set and get, so value is public. 
			   // I acknowledge that this is bad programming practice but for the sake of the project it shall remain as is.
};

#endif