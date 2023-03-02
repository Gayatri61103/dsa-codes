#include <stdio.h>

void linear_search(int a[],int n)
{
	int key;
	printf("ele to search :");
	scanf("%d",&key);
	for(int i=0;i<n;i++)
	{
		if (key==a[i])
			printf("ele found");
		else{
			printf("ele not found");
			break;
		}
	}
}

int main(){
	int s;
	printf("enter max ele in array :");
        scanf("%d",&s);
	int a[s];
	printf("enter ele in array :");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	linear_search(a,s);
	return 0;
}
