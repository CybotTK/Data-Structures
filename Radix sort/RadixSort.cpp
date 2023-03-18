#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
using namespace std;
using namespace std::chrono;

int v[10001], p10=1, p16=1, n;   
deque <int> baza10[10], baza16[16];
int nrcifremax, nrc, pasimax;


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

int main()
{ 
    cin>>n;
    for (int i=0;i<n;i++)
    {   cin>>v[i];
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
    auto start = high_resolution_clock::now();
    RadixSortb10();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    auto start1 = high_resolution_clock::now();
    RadixSortb16();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    for (int i=0;i<n;i++)
        cout<<v[i]<<" ";
}
///121 432 564 23 1 45 788