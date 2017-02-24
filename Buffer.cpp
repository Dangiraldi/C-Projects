//Daniel Fries-Giraldi
//Producer and Consumer Problem
//CSCI 375

#define MAX_THREADS 2

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

DWORD WINAPI insert(LPVOID);
DWORD WINAPI remove(LPVOID);
HANDLE hThreads[MAX_THREADS];
DWORD id[MAX_THREADS];
DWORD waiter;


int *buffer;
int buffSize;
int count1;
int count2;
int userSize;

static int in=0;
static int out=0;

DWORD WINAPI producer(LPVOID);
DWORD WINAPI consumer(LPVOID);

int main(int argc,char* argv[])
{
	int userLimit;
	cout<<"Enter desired buffer size: ";
	cin>>userSize;
	cout<<"Enter a counter limit: ";
	cin>>userLimit;
	buffer=new int[userSize];

	hThreads[0]=CreateThread(NULL,0,producer,(LPVOID)userLimit,0,&id[0]);
	hThreads[1]=CreateThread(NULL,0,consumer,(LPVOID)userLimit,0,&id[1]);
	waiter=WaitForMultipleObjects(MAX_THREADS,hThreads,TRUE,INFINITE);

	for(int i=0;i<MAX_THREADS;i++)
		CloseHandle(hThreads[i]);

	system("pause");
	return 0;
}
DWORD WINAPI producer(LPVOID x)
{
	int userLimit=(int)x;
	srand(time(NULL));

	while(count2<=userLimit)
	{
		int i=rand()%100;
		while(count1==userSize)
		{}
		buffer[in]=i;
		cout<<"Produced item "<<i<<endl;
		in=(in+1)%userSize;
		count1++;
		count2++;
	}
	return (DWORD)x;
}
DWORD WINAPI consumer(LPVOID x)
{
	int userLimit=(int)x;
	int consumed;
	while(count2<=userLimit)
	{
		while(count1==0)
		{}
		consumed=buffer[out];
		cout<<"Consumed item "<<consumed<<endl;
		out=(out+1)%userSize;
		count2++;
		count1--;
	}
	return DWORD(x);
}