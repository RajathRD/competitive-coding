// Problem - given length n, and 2 arrays A and B of length n, find every pair (a,b) such that a belongs to A and b belongs to B,
 // and GCD(A,B) ! = 1

#include<stdio.h>
int FindNumPairs(int[], int[], int);
int GCD(int, int);
int main()
{
	int n, i, num_pairs = 0;
	printf("enter n \n");
	scanf("%d", &n);
	int A[n];
	int B[n];
	printf("enter A \n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("enter B \n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &B[i]);
	}
	printf("B entered \n");
	num_pairs = FindNumPairs(A,B,n);
	printf("%d", num_pairs);
	return 0;
}


int FindNumPairs(int A[], int B[], int n)
{
	printf("entering function \n");
	int num_pairs = 0, i, j, number;


	for(i = 0; i < n; i++)
	{
		printf("i is %d num_pairs is %d \n", i, num_pairs);
		number = A[i];
		for(j = 0; j < n; j++)
		{
			if(GCD(number, B[j])>1)
				num_pairs++;
		}
	}
	return num_pairs;
}

int GCD(x,y)
{
	int max, temp, second;
	char c;
	printf("x and y are %d %d\n", x,y);
	if(x>y)
	{
		max = x;
		second = y;
	}
	else
	{
		max = y;
		second = x;
	}
	// printf("max and second are %d, %d \n", max, second);
	while((max!=1) && (max != second))
	{
		max = max - second;
		// if(max==second)
		// 	printf("max, second is %d %d \n", max, second );
		// return 1;
		if((max !=1) && (second>max))
		{
			// printf("max, second is %d %d \n", max, second );
			scanf("%c", &c);
			temp = max;
			max = second;
			second = temp;
		}
	}
	printf("GCD of %d, %d is %d \n", x,y,max);
	return max;
}