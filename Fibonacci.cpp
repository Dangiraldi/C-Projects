// Name: Daniel Fries-Giraldi
// ID: 1634
// CSCI 377 Section 63015
// Homework 1, Problem 1

#include <iostream>
using namespace std;

unsigned long RTotal,ITotal,countR,countI;

unsigned long recursive(unsigned long n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	else
		return recursive(n-1)+recursive(n-2);
}

unsigned long countRec(unsigned long n)
{
	if(n==1||n==2)
	{
		countR+=2;
	}
	else
		countR+=2;
		RTotal+=countR;
		countRec(n-1)+countRec(n-2);
		return RTotal;
}

unsigned long iterative(unsigned long n)
{
    unsigned long previous = 1;
    unsigned long current = 1;
    unsigned long next = 1;
    for (unsigned long i=3;i<=n;i++) 
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}

unsigned long countIt(unsigned long n)
{
    unsigned long previous = 1;
    unsigned long current = 1;
    unsigned long next = 1;
	countI+=4;
    for (unsigned long i=3;i<=n;i++) 
    {
        next = current + previous;
        previous = current;
        current = next;
		countI+=3;
    }
	countI+=2;
	ITotal+=countI;
    return ITotal;
}

int main()
{
    unsigned long n;
	
    cout<<"Enter the integer n to find nth fibonacci number: ";
    cin>>n;

    cout<<"Iterative: "<<iterative(n)<<"\tSteps: "<<countIt(n)<<endl;
	cout<<"Recursive: "<<recursive(n)<<"\tSteps: "<<countRec(n)<<endl;

	system("pause");
    return 0;
}