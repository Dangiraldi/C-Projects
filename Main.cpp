#include <iostream>
#include "Complex.h"
using namespace std;

int main(Complex x, Complex y) //Main takes two of class Complex as arguments. Makes life easier.
{
	cout<<"Format: [number1] [operation] [number2]"<<endl; //format for entering in equation. Only binary equations accepted
	char operation;
	cin>>x.value>>operation>>y.value; 

	if(operation=='+')
	{
		cout<<x.value+y.value<<endl; //Overloading in action!!!
		system("pause");
	}
	else
	if(operation=='-')
	{
		cout<<x.value-y.value<<endl;
		system("pause");
	}
	else
	if(operation=='*')
	{
		cout<<x.value*y.value<<endl; 
		system("pause");
	}
	else
	if(operation=='/')
	{
		cout<<x.value/y.value<<endl;
		system("pause");
	}
	else
		system("pause");
		return 0;

}