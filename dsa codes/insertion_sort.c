#include <stdio.h>

int main(){
	int a[6]={1,5,7,2,8,4};
	int i,j,key;
	for (i=1;i<6;i++)
	{
		key=a[i];
		j=i-1;
		while (j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	for (i=0;i<6;i++)
        {
		printf("%d ",a[i]);
	}
	return 0;
}

