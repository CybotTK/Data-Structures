#include <iostream>
#include <fstream>

using namespace std;

ifstream f("algsort.in");
ofstream g("algsort.out");

unsigned int v[500001], n;

void ShellSort()
{
    int interval=n/2;
    while (interval>0)
    { int temp=0;
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

int main()
{
    f>>n;
    for (int i=0;i<n;i++)
        f>>v[i];
    ShellSort();
    for (int i=0;i<n;i++)
        g<<v[i]<<" ";
    return 0;
}
