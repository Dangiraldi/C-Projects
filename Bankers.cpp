//Daniel Fries-Giraldi
//CSCI 375

#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int np=4;
	int nr=3;
	int i, x, j, k, a;
	vector<int> seq;
	int alloc[4][3];
    int max[4][3];
    int av[4+1][3];
    int need[4][3];
    cout << "Enter the allocation matrix." << endl;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            cin >> x;
            alloc[i][j] = x;
        }
    }
  
    cout << "Enter the max matrix." << endl;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            cin >> x;
            max[i][j] = x;
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    cout << "Need matrix." << endl;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Enter first entry of availability matrix." << endl;
    for (j = 0; j < nr; j++)
    {
        cin >> x;
        av[0][j] = x;
    }
    bool flag[2];
    bool test = true; 
    for (i = 0; i < np; i++)
        flag[i] = false; 
    int cnt = 0;
    while (cnt == 0)
    {
    for (i = 0; i < np; i++)
    {
          if (flag[i] == false)
          {
              for (j = 0; j < nr; j++)
              {
                  if ((need[i][j] > av[i][j]))
                     test = false;
                  if ((need[i][j] <= av[i][j]))
                     test = true;
              }
              if (test == true) 
              {
                     seq.push_back(i); 
                     for (k = 0; k < nr; k++)
                     {
                         av[i+1][k] = av[i][k] + alloc[i][k];
                     }
                      flag[i] = true; 
              } 
                
              }
    } 
    for (a = 0; a < np; a++)
    {
        if (flag[a] == false)
        {
           cnt = 0; 
           break;
        }
        else
            cnt++;
    } 
    
    } 
    
    cout << "A possible sequence:" << endl;
    for (i = 0; i < np; i++)
        cout << "P" << seq[i] << " -> ";
    cout << endl;
   
    system("PAUSE");
    return 0;
}