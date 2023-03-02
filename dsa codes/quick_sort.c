#include <stdio.h>

void quicksort(int a[],int first,int last)
{
	int i=first;
	int pivot=a[first];
	int j=last;
	while(i<j)
	{
		while (a[i]<=pivot && i<=last)
			i++;
		while (a[j]>pivot && j>first)
			j--;
		if (i<j)
		{
			temp= a[i];
			a[i]= a[j];
			a[j]=temp;
		}
	}
	int temp=pivot;
	pivot=a[j];
	a[j]=temp;
	quicksort(int a[],first,j-1);
	quicksort(int a[],first,j-1);
}
int main()
{
	int a[6]={5,2,8,4,1,3};
   	quicksort(a,0,5);
   	printf("Order of Sorted elements: ");
   	for(int i=0;i<6;i++)
   		printf(" %d",a[i]);
	return 0;
}
