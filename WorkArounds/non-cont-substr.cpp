#include <stdio.h>
#include <math.h>

void printPowerSet(int *set, int set_size)
{
	/*set_size of power set of a set with set_size
	n is (2**n -1)*/
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j;

	for(counter = 0; counter < pow_set_size; counter++)
	{
	for(j = 0; j < set_size; j++)
	{
		if(counter & (1<<j))
			printf("%d", set[j]);
	}
	printf("\n");
	}
}

/*Driver program to test printPowerSet*/
int main()
{
	int set[] = {1,2,3};
	printPowerSet(set, 3);

	getchar();
	return 0;
}
