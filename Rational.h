#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
	Rational(int=0,int=1);			//Constructor, initializes a Rational with numerator and denominator. UNLESS you define the rational(s) in the main function, call setValues.
	void setNum(int);				//Sets the numerator.
	const int getNum();				//Returns the denominator.
	void setDen(int);				//Sets the denominator, as long as the argument does not equal 0. If it does, will call set values for the rational, and values will have to be input again.
	const int getDen();				//Returns the denominator.
	void Add(Rational&);			//Adds the two fractions and reduces.
	void Subtract(Rational&);		//Subtracts the two fractions and reduces.
	void Multiply(Rational&);		//Multiplies the two fractions and reduces.
	void Divide(Rational&);			//Divides the two fractions and reduces.
	const void displayMessage();	//Neatly displays the values of the two Rationals as both fraction and decimal. If a fraction can be reduced, it will show both the input and the reduced form.
	void setValues();				//Sets the input variables to the desired rational. UNLESS you define the rational(s) in the main function, call this after constructor.
	~Rational();					//Deconstructor
private:
	void reduce();
	const void printFrac();
	const void printDec();
	int numerator,denominator,num,den,smaller,ans;
};

#endif