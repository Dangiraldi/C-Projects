#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex()
{

}
Complex::Complex(int x)
{
	setVal(x);
}
Complex Complex::operator+(const Complex& c)
{
	Complex result;
	result.value=value+c.value;
	return result;
}
Complex Complex::operator-(const Complex& c)
{
	Complex result;
	result.value=value-c.value;
	return result;
}
Complex Complex::operator*(const Complex& c)
{
	Complex result;
	result.value=value*c.value;
	return result;
}
Complex Complex::operator/(const Complex& c)
{
	Complex result;
	result.value=value/c.value;
	return result;
}
void Complex::setVal(int x)
{
	value=x;
}
int Complex::getVal()
{
	return value;
}
ostream &operator<<(ostream &output,const Complex &C) //I finally figured these out!
{
	output<<C.value;
	return output;
}
istream &operator>>(istream &input, Complex &C)
{
	input>>C.value;
	return input;
}