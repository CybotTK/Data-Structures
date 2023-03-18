#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;
using namespace std::chrono;

ifstream f("date.in");
ofstream g("Test.out");

int temp[501];
int v[1001], p10=1, p16=1, n, aux[1001];
int fr[1001];   
int maxi;
deque <int> baza10[10], baza16[16];
int nrcifremax, nrc, pasimax;

void Merge(int low, int high, int mid)
{ int i=low;
  int j=mid+1;
  int k=0;
  while (i<=mid && j<=high)
  { if (v[i]<=v[j])
     temp[k++]=v[i], i++;
    else temp[k++]=v[j], j++;
  }
  while (i<=mid)
  { temp[k++]=v[i];
    i++;
  }
  while (j<=high)
  { temp[k++]=v[j];
    j++;
  }
  k=0;
  for (i=low;i<=high;i++)
    v[i]=temp[k++];
}

void MergeSort(int low, int high)
{ if (low<high)
  { int mid=low+(high-low)/2;
    MergeSort(low, mid);
    MergeSort(mid+1, high);
    Merge(low, high, mid);
  }
}

void RadixSortb10()
{ while (nrcifremax)
  { for (int i=0;i<n;i++)
    { int cifra=v[i]/p10%10;
      baza10[cifra].push_back(v[i]);
    }
    int k=0;
    for (int i=0;i<10;i++)
    { while(baza10[i].size())
      { v[k++]=baza10[i].front();
        baza10[i].pop_front();
      }
    }
    nrcifremax--;
    p10*=10;
  }
}

void RadixSortb16()
{ while (pasimax)
  { for (int i=0;i<n;i++)
    { int cifra=v[i]/p16%16;
      baza16[cifra].push_back(v[i]);
    }
    int k=0;
    for (int i=0;i<16;i++)
    { while(baza16[i].size())
      { v[k++]=baza16[i].front();
        baza16[i].pop_front();
      }
    }
    pasimax--;
    p16*=10;
  }
}

void ShellSort()
{
    int interval=n/2;
    while (interval>0)
    { int temp;
      for (int i=interval; i<n;i++)
      { int j=i;
        temp=v[i];
        while (j>=interval && v[j-interval]>temp)
        { v[j]=v[j-interval];
          j-=interval;
        }
        v[j]=temp;
      }
      interval/=2;
    }
}

void CountSort()
{ for (int i=0;i<n;i++)
    fr[v[i]]++;
  for (int i=0;i<=maxi;i++)
    if (fr[i]>0)
      for (int j=1;j<=fr[i];j++)
        v[i]=i;
}

void InsertionSort()
{
    for (int i=0;i<n;i++)
    {   int key=v[i];
        int j=i-1;
        for (;j>=0;j--)
            if (v[j]>key)
                v[j+1]=v[j];
            else break;
        v[j+1]=key;
    }
}

void ResetareVector()
{ for (int i=0;i<n;i++)
    v[i]=aux[i];
}

int main()
{
  n=1001;
  for (int i=0;i<n;i++)
    { v[i]=1000000000+rand()%2147483646;
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

//radixsort
  
  auto start = high_resolution_clock::now();
  RadixSortb10();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by function RadixSortb10: "
       << duration.count() << " microseconds" << endl;

  ResetareVector();

  auto start1 = high_resolution_clock::now();
  RadixSortb16();
  auto stop1 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
    
  cout << "Time taken by function RadixSortb16: "
       << duration1.count() << " microseconds" << endl;

  ResetareVector();

//MergeSort

  auto start2 = high_resolution_clock::now();
  MergeSort(0, n-1);
  auto stop2 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(stop2 - start2);

  cout << "Time taken by function MergeSort: "
       << duration2.count() << " microseconds" << endl;

  ResetareVector();

//Shellsort

  auto start3 = high_resolution_clock::now();
  ShellSort();
  auto stop3 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(stop3 - start3);

  cout << "Time taken by function ShellSort: "
       << duration3.count() << " microseconds" << endl;

  ResetareVector();

//CountSort

  if (maxi>1000001) cout<<"Prea mari numerele sefu\n";
  else 
  { auto start4 = high_resolution_clock::now();
    CountSort();
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Time taken by function CountSort: "
         << duration4.count() << " microseconds" << endl;
  }

  ResetareVector();

//Insertion Sort

  auto start5 = high_resolution_clock::now();
  InsertionSort();
  auto stop5 = high_resolution_clock::now();
  auto duration5 = duration_cast<microseconds>(stop5 - start5);

  cout << "Time taken by function InsertionSort: "
       << duration5.count() << " microseconds" << endl;

//IntroSort

  ResetareVector();

  auto start6 = high_resolution_clock::now();
  sort(v, v+n);
  auto stop6 = high_resolution_clock::now();
  auto duration6 = duration_cast<microseconds>(stop6 - start6);

  cout << "Time taken by function IntroSort: "
       << duration6.count() << " microseconds" << endl;

  for(int i=0;i<n;i++)
    { g<<aux[i]<<" ";
      if(i%100==0 && i>1) g<<'\n';
    }

  return 0;
}
