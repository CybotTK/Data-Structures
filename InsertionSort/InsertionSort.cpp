#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

ifstream f("algsort.in");
ofstream g("algsort.out");

int temp[501];
int v[1000001], p10=1, p16=1, n, aux[1000001];
int fr[1000001];   
int maxi;
deque <int> baza10[10], baza16[16];
int nrcifremax, nrc, pasimax;

void InsertionSort()
{
    for (int i=1;i<n;i++)
    {   int key=v[i];
        int j=i-1;
        for (;j>=0;j--)
            if (v[j]>key)
                v[j+1]=v[j];
            else break;
        v[j+1]=key;
    }
}

int main()
{
    f>>n;
    for (int i=0;i<n;i++)
    {f>>v[i];
     maxi=max(v[i],maxi);
     int x=v[i];
        nrc=0;
        while (x)
        { nrc++;
          x/=10;
        }
        nrcifremax=max(nrcifremax, nrc);
        x=v[i];
        nrc=0;
        while (x)
        { nrc++;
          x/=16;
        }
        pasimax=max(pasimax, nrc);
    }

    auto start5 = high_resolution_clock::now();
    InsertionSort();
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);

    cout << "Time taken by function InsertionSort: "
       << duration5.count() << " microseconds" << endl;
    
    for (int i=0;i<n;i++)
        g<<v[i]<<" ";

    return 0;
}
