#include <iostream>
#include <fstream>
using namespace std;

ifstream f("algsort.in");
ofstream g("algsort.out");

int v[500001], temp[500001];
int n;

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

int main()
{
    f>>n;
    for (int i=0;i<n;i++)
        f>>v[i];
    MergeSort(0, n-1);
    for (int i=0;i<n;i++)
        g<<v[i]<<" ";
    return 0;
}
