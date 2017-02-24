#include <iostream>
#include "Rational.h"
using namespace std;

Rational result;

Rational::Rational(int n,int d)
{
	setNum(n);
	setDen(d);
}
void Rational::setNum(int n)
{
	numerator=n;
}
const int Rational::getNum()
{
	return numerator;
}
void Rational::setDen(int d)
{
	if(d==0)
	{
		cout<<"\nInvalid fraction, UNDEFINED\n";
		cout<<"\nEnter a different denominator.\n\n";
		setValues();
	}
	else
		denominator=d;
}
const int Rational::getDen()
{
	return denominator;
}
void Rational::reduce()
{
	smaller=(getNum()>getDen())?getNum():getDen();
	ans=1;
	for(int i=smaller;i>=1;i--)
	{
		if((getNum()%i==0)&&(getDen()%i==0))
		{
			ans=i;
			break;
		}
	}
	setNum(getNum()/ans);
	setDen(getDen()/ans);
}
void Rational::Add(Rational &f1)
{
	result.setDen(getDen()*f1.getDen());
	result.setNum((getNum()*f1.getDen())+(f1.getNum()*getDen()));
	result.reduce();
	cout<<endl;
	printFrac();
	cout<<" + ";
	f1.printFrac();
	cout<<" = ";
	result.printFrac();
	cout<<" or ";
	result.printDec();
	cout<<endl;
}
void Rational::Subtract(Rational &f1)
{
	result.setDen(getDen()*f1.getDen());
	result.setNum((getNum()*f1.getDen())-(f1.getNum()*getDen()));
	result.reduce();
	cout<<endl;
	printFrac();
	cout<<" - ";
	f1.printFrac();
	cout<<" = ";
	result.printFrac();
	cout<<" or ";
	result.printDec();
	cout<<endl;
}
void Rational::Multiply(Rational &f1)
{
	result.setNum(getNum()*f1.getNum());
	result.setDen(getDen()*f1.getDen());
	result.reduce();
	cout<<endl;
	printFrac();
	cout<<" * ";
	f1.printFrac();
	cout<<" = ";
	result.printFrac();
	cout<<" or ";
	result.printDec();
	cout<<endl;
}
void Rational::Divide(Rational &f1)
{
	result.setNum(getNum()*f1.getDen());
	result.setDen(getDen()*f1.getNum());
	result.reduce();
	cout<<endl;
	printFrac();
	cout<<" / ";
	f1.printFrac();
	cout<<" = ";
	result.printFrac();
	cout<<" or ";
	result.printDec();
	cout<<endl;
}
const void Rational::printFrac()
{
	cout<<getNum()<<"/"<<getDen();
}
const void Rational::printDec()
{
	double N=getNum();
	double D=getDen();
	double decimal=N/D;
	if(N==0)
		cout<<"0.00";
	else
		cout<<decimal;
}
const void Rational::displayMessage()
{
	result.setNum(getNum());
	result.setDen(getDen());
	result.reduce();
	if(result.getNum()<getNum())
	{
		cout<<"\n";
		printFrac();
		cout<<" or ";
		result.printFrac();
		cout<<" can also be written as ";
		printDec();
		cout<<endl;
	}
	else
	{
		cout<<"\n";
		printFrac();
		cout<<" can also be written as ";
		printDec();
		cout<<endl;
	}
}
void Rational::setValues()
{
	denominator=0;
	cout<<"Enter the numerator: ";
	cin>>numerator;
	do{
		cout<<"\nEnter the denominator: ";
		cin>>denominator;
		if(denominator==0)
		{
			cout<<"\nInvalid fraction, UNDEFINED\n";
			cout<<"\nEnter a different denominator.\n";
		}
	}while (denominator==0);
	setNum(numerator);
	setDen(denominator);
	cout<<endl;
}
Rational::~Rational()
{

}