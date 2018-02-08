#include<stdio.h>

int main()
{
  char ch[10001];
  int T,N,a = 97,i;
  scanf("%d",&T);
  for(i=0; i<10001; i++)
  {
    ch[i] = a;
    a = (a-97+1)%26 + 97;
  }
  while(T--)
  {
    scanf("%d",&N);
    char temp = ch[N];
    ch[N] = '\0';
    printf("%s\n",ch);
    ch[N] = temp;
  }
  return 0;
}
