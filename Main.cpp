#include <iostream>
using namespace std;

void pageTable(unsigned int);

int main(unsigned int address)
{
	cout<<"Enter Address(32-bit): ";
	cin>>address;
	pageTable(address);

	system("pause");
	return 0;
}

void pageTable(unsigned int a)
{
	unsigned int pageNum,offset;
	pageNum=a/4096; //4096 because 4KB
	offset=a%4096;
	cout<<"The address "<<a<<" contains: \nPage number = "<<pageNum<<"\nOffset = "<<offset<<endl;
}