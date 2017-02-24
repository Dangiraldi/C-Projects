#include <iostream>

#include <cstdlib>

#include <ctime>

#include <iomanip>

#include <windows.h>

using namespace std;

const int finish = 70;

void Tortoise (int *);

void Hare(int *);

void positions(int *,int *);

int main()
{
   int T=1;
   int H=1;
   int timer=0;

   srand(time(0));

   cout << "ON YOUR MARK, GET SET\nGO!!!!\n";

   while (T<finish && H<finish)
   {
           Tortoise(&T);
           Hare(&H);
           positions(&T,&H);
		   ++timer;
           Sleep(500);
   }

   if(T<H)
   {
      cout << "\nTORTOISE WINS!!! YAY!!!\n";
   }
   else
   if(T>H)
   {
           cout << "\nHare wins. Yuch.\n";
   }
   else
   if(T==H)
   {
      cout << "It's a tie!\n";
   }
        cout<< "TIME ELAPSED = "<<timer<<" seconds"<<endl;
   cin.get();
   return 0;
}

void Tortoise(int *turtlePtr)
{
   int x=1+rand()%10;

   if (x>=1 && x<=5)       // fast plod
      *turtlePtr+=3;

   else
   if (x==6 || x==7)        // slip
      *turtlePtr-=6;

   else                    // slow plod
      ++(*turtlePtr);

   if (*turtlePtr<1)
      *turtlePtr=1;

   else
   if (*turtlePtr > finish)
      *turtlePtr = finish;

}

void Hare(int *harePtr)
{
   int y=1+rand()%10;

   if (y>=1 && y<=5)       // fast plod
      *harePtr+=3;

   else
   if (y==6 || y==7)       // slip
      *harePtr-=6;

   else                    // slow plod
      ++(*harePtr);

   if (*harePtr<1)
      *harePtr=1;

   else if (*harePtr>finish)
      *harePtr=finish;
}


void positions(int *bunnyPtr,int *snapperPtr)
{
   if (*bunnyPtr == *snapperPtr)
      cout<<setw(*bunnyPtr)<<"OUCH !!!";

   else if (*bunnyPtr < *snapperPtr)
      cout<<setw(*bunnyPtr)<<"H"
          <<setw(*snapperPtr-*bunnyPtr)<<"T";

   else
      cout<<setw(*snapperPtr)<<"T"
          <<setw(*bunnyPtr-*snapperPtr)<<"H";

   cout<<"\n";

}