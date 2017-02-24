#include <iostream>
#include "Rational.h"
using namespace std;

void printLine();

int main()
{
	
	Rational frac1,frac2;

	frac1.setValues();
	frac2.setValues();
	
	frac1.displayMessage();
	frac2.displayMessage();

	printLine();

	frac1.Add(frac2);
	frac1.Subtract(frac2);
	frac1.Multiply(frac2);
	frac1.Divide(frac2);

	frac1.~Rational();
	frac2.~Rational();

	printLine();

	system("pause");
	return 0;
}

void printLine()
{
	cout<<"---------------------------------\n";
}