#include<stdio.h>

void print(int arr[], int start, int end)
{
    int i;
    for(i=start;i<=end;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}


void substrings(int arr[], int n)
{
    int pass,j,start,end;
    int no_of_strings = n-1;

    for(pass=0;pass<n;pass++)
    {
        start = 0;
        end = start+pass;
        for(j=no_of_strings;j>=0;j--)
        {
            print(arr,start, end);
            start++;
            end = start+pass;
        }
        no_of_strings--;
    }

}

int main()
{
    int str[] = {1,2,3,4,5,6};
    substrings(str,6);
    return 0;
}
