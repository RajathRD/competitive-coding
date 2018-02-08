#include<stdio.h>
#include<stdlib.h>

int sumer(int *arr)
{
  int sum = 0;
  for(int i=0; i<3; i++)
  {
    sum += arr[i];
  }
  printf("%d",sum);
  return sum;
}
int main()
{
  int *a = (int *) malloc ( 3 );
  a[1] = 10;
  a[0] = 10;
  a[2] = 5;
  sumer(a);
}
