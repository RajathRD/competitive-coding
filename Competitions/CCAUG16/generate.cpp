#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
  ofstream fout;
  string file = "large_in";
  fout.open(file.c_str());
  int T = 1;
  fout<<T<<endl;
  while(T--)
  {
    int N = 200000;
    fout<<N<<endl;
    for(int i=0; i<N; i++)
      fout<<rand()% 200 - 100<<" ";
    fout<<endl;
    fout<<1<<" "<<1000<<endl;
  }
  return 0;
}
