#include <stdio.h>
int main(){
	int m,n;
	printf("enter rows and column for 2d matrix :");
	scanf("%d %d",&m,&n);
	int a[m][n];
	printf("enter elements :");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	//counting non zeroes
	int z=0,nz=0;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (a[i][j] !=0)
				nz++;
		}
	}
	int s[10][3];
	if (nz < ((m*n)/2))
	{
		s[0][0]=m;
		s[0][1]=n;
		s[0][2]=nz;
		int k=1;
		for (int i=0;i<m;i++)
        	{
                	for (int j=0;j<n;j++)
                	{
                        	if (a[i][j] !=0)
				{
					s[k][0]=i;
					s[k][1]=j;
					s[k][2]=a[i][j];
				}
			}
		}
	}
	else
		printf("not a sparse matrix");
	printf("\n\n");
	for (int i=0;i<nz+1;i++)
        {
                for (int j=0;j<3;j++)
                {
                        printf("%d",s[i][j]);
                }
		printf("\n");
        }
	return 0;
}
