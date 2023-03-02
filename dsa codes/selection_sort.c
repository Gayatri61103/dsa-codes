#include <stdio.h>

int main(){
	int a[6]={5,7,2,6,1,8};
	int i,j,temp;
	for (i=0;i<6;i++)
	{
		int min=i;
		for (j=i+1;j<6;j++)
		{
			if (a[min]>a[j])
				min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	for (i=0;i<6;i++)
        {
		printf("%d ",a[i]);
	}
	return 0;
}
