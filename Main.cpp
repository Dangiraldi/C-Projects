#include <string>
#include <iostream>
#include "Prof.h"
#include "List.h"

using namespace std;

int main()
{
	int count;
	int choice=0;
	List Roster;
	Prof x;
	cout<<"What would you like to do?";
	cout<<"\n1. Add professors\n2. Search for a professor\n3. Sort the list\n4. Display the list\n5. Delete a professor"<<endl;
	cin>>choice;
	while(choice!=-100)
	{
		if(choice==1)
		{
			cout<<"How many professors would you like to add? ";
			cin>>count;
			cout<<"\nType the name, followed by room, and then phone number. Any'-' and '.' can be included."<<endl;
			for(int i=0;i<count;i++)
			{
				cin>>x;
				Roster.Insert(x);
				cout<<"Professor added."<<endl;
				if(i<count-1)
					cout<<"Next professor: ";
			}
			cout<<"List is full. Sorting names."<<endl;
			Roster.Sort();
			choice=0;
		}
		else
		if(choice==2)
		{
				Prof temp;
				cout<<"Enter the professor's details: ";
				cin>>temp;
				Roster.Search(temp);
				choice=0;
		}
		else
		if(choice==3)
		{
			Roster.Sort();
			choice=0;
		}
		else
		if(choice==4)
		{
			Roster.Display();
			choice=0;
		}
		else
		if(choice==5)
		{
			char first[256];
			char last[256];
			cout<<"Enter the professor's first name: ";
			cin>>first;
			cout<<"Enter the professor's last name: ";
			cin>>last;
			Prof *temp=new Prof(first,last,NULL,NULL);
			Roster.Delete(temp);
			choice=0;
		}
		else
		{
			char decide;
			cout<<"Would you like to do something else?(y/n) ";
			cin>>decide;
			if(decide=='y')
			{
				cout<<"\nWhat would you like to do?";
				cout<<"\n1. Add professors\n2. Delete a professor\n3. Sort the list\n4. Display the list\n5. Search for a professor\n6. Exit"<<endl;
				cin>>choice;
			}
			else
			if(decide=='n')
			{
				choice=-100;
			}
			else
			{
				cout<<"\nInvalid option. Goodbye";
				choice=-100;
			}
		}
	}
	
	system("pause");
	return 0;
}