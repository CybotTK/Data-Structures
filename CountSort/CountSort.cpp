#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

ifstream f("algsort.in");
ofstream g("Test.out");

int temp[501];
int v[10000001], p10=1, p16=1, n, aux[10000001];
int fr[1000001];   
int maxi;
deque <int> baza10[10], baza16[16];
int nrcifremax, nrc, pasimax;

void CountSort()
{ for (int i=0;i<n;i++)
    fr[v[i]]++;
  for (int i=0;i<=maxi;i++)
    if (fr[i]>0)
      for (int j=1;j<=fr[i];j++)
        v[i]=i;
}

int main()
{
  n=10000001;
  for (int i=0;i<10000001;i++)
    { v[i]=rand()%1000001;
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

  for (int i=0;i<n;i++)
    aux[i]=v[i];

  if (maxi>1000001) cout<<"Prea mari numerele sefu";
  else 
  { auto start4 = high_resolution_clock::now();
    CountSort();
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Time taken by function CountSort: "
         << duration4.count() << " microseconds" << endl;
  }

  for(int i=0;i<10000001;i++)
    { g<<aux[i]<<" ";
      if(i%100000==0 && i>1) g<<'\n';
    }

  return 0;
}
