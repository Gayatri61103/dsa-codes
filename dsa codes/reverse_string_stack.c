#include <stdio.h>
int top=-1;
int push()
{
        top=top+1;
        return( top );
}

int pop()
{
	//top=n;
        top=top-1;
	return (top);
}
int main(){
	int k;
	printf("no of chars : ");
	scanf("%d",&k);
	printf("enter string :");
	char a[k],b[k];
	scanf("%s",a);
	for(int i=0;i<k;i++)
	{
		int p=push();
		b[i] = a[p];
	}
	for (int i=0;i<k;i++)
	{
		int l = pop();
		a[i] = b[l];
	}
	for(int i=0;i<k;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}
