#include <iostream>
#include <ctime>
using namespace std;

void r1();
void r2();
void r3();
void r4();
void w1();
void w2();
void w3();
void panic();
void swap(int,int);
void P(int);
void V(int);

int r1count=0;
int r2count=0;
int r3count=0;
int r4count=0;
int i1=0;
int i2=0;
int i3=0;
int i4=0;
int rS=3;
int wS=1;

int main()
{
	for(int i=0;i<100;i++)
	{
		int proc=rand()%7;
		switch(proc){
		case 0: r1(); break;
		case 1: r2(); break;
		case 2: r3(); break;
		case 3: r4(); break;
		case 4: w1(); break;
		case 5: w2(); break;
		case 6: w3(); break;
		default: panic();
		}
	}
	cin.get();
	return 0;
}

void r1()
{
	switch(r1count){
	case 0: cout<<"R1 Attempting to enter critical section(0)"<<endl;
	case 1: r1count++;cout<<"R1 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"R1 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"R1 Someone inside CS"<<endl;break;}
	case 4: r1count++;break;
	case 5: if(i1<100){r1count++;break;}else r1count=7;break;
	case 6: i1++;r1count--;cout<<"R1 Inside CS"<<endl;break;
	default: panic();
	}
}
void r2()
{
	switch(r2count){
	case 0: cout<<"R2 Attempting to enter critical section(0)"<<endl;
	case 1: r2count++;cout<<"R2 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"R2 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"R2 Someone inside CS"<<endl;break;}
	case 4: r2count++;break;
	case 5: if(i2<100){r2count++;break;}else r2count=7;break;
	case 6: i2++;r2count--;cout<<"R2 Inside CS"<<endl;break;
	default: panic();
	}
}
void r3()
{
	switch(r3count){
	case 0: cout<<"R3 Attempting to enter critical section(0)"<<endl;
	case 1: r3count++;cout<<"R3 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"R3 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"R3 Someone inside CS"<<endl;break;}
	case 4: r3count++;break;
	case 5: if(i3<100){r3count++;break;}else r3count=7;break;
	case 6: i3++;r3count--;cout<<"R3 Inside CS"<<endl;break;
	default: panic();
	}
}
void r4()
{
	switch(r4count){
	case 0: cout<<"R4 Attempting to enter critical section(0)"<<endl;
	case 1: r4count++;cout<<"R4 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"R4 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"R4 Someone inside CS"<<endl;break;}
	case 4: r4count++;break;
	case 5: if(i4<100){r4count++;break;}else r4count=7;break;
	case 6: i4++;r3count--;cout<<"R4 Inside CS"<<endl;break;
	default: panic();
	}
}
void w1()
{
	switch(r1count){
	case 0: cout<<"W1 Attempting to enter critical section(0)"<<endl;
	case 1: r1count++;cout<<"W1 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"W1 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"W1 Someone inside CS"<<endl;break;}
	case 4: r1count++;break;
	case 5: if(i1<100){r1count++;break;}else r1count=7;break;
	case 6: i1++;r1count--;cout<<"W1 Inside CS"<<endl;break;
	default: panic();
	}
}
void w2()
{
	switch(r2count){
	case 0: cout<<"W2 Attempting to enter critical section(0)"<<endl;
	case 1: r2count++;cout<<"W2 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"W2 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"W3 Someone inside CS"<<endl;break;}
	case 4: r2count++;break;
	case 5: if(i2<100){r2count++;break;}else r2count=7;break;
	case 6: i2++;r2count--;cout<<"W2 Inside CS"<<endl;break;
	default: panic();
	}
}

void w3()
{
	switch(r3count){
	case 0: cout<<"W3 Attempting to enter critical section(0)"<<endl;
	case 1: r3count++;cout<<"W3 Attempting to enter critical section(1)"<<endl;break;
	case 2: cout<<"W3 Attempting to enter critical section(2)"<<endl;
	case 3: if(rS>0){rS--;cout<<"W3 Someone inside CS"<<endl;break;}
	case 4: r3count++;break;
	case 5: if(i3<100){r3count++;break;}else r3count=7;break;
	case 6: i3++;r3count--;cout<<"W3 Inside CS"<<endl;break;
	default: panic();
	}
}
void P(int S)
{
	while(S<=0)
	{
		;
	}
	S--;
}
void V(int S)
{
	S++;
}
void panic()
{
	cout<<"ERROR!!!"<<endl;
}
void swap(int x,int y)
{
	int temp=x;
	x=y;
	y=temp;
}