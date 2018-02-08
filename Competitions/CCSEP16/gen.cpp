#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main()
{
  int T=10;
  ofstream fout;
  fout.open("input.txt");
  int N=1000,M=100000;
  fout<<T<<endl;
  while(T--)
  {
    fout<<N<<" "<<M<<endl;
    for(int i=0; i<M; i++)
    {

      fout<<rand()%N+1<<" "<<rand()%N+1<<endl;
    }
  }
  return 0;
}
