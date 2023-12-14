
#include<stdio.h>

void printsparse(int[20][20]);
void readsparse(int[20][20]);
void transpose(int[][3],int[][3]);

int main()
{
	int b1[20][20],b2[20][20],m,n;
	printf("Enter the Size of the Matrix (rows x columns):");
	scanf("%d %d",&m,&n);
	b1[0][0]=m;
	b1[0][1]=n;
	readsparse(b1);
	transpose(b1,b2);
	printsparse(b2);
}

void readsparse(int b[20][20])
{
	int i,t;
	printf("Enter the number of non-zero elements:");
	scanf("%d",&t);
	b[0][2]=t;
	for(i=1;i<=t;i++)
	{
		printf("Enter the Three values of matrix(row,col,value):");
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	}
}

void printsparse(int b[20][20])
{
	int i,n;
	n=b[0][2];
	printf("\nAfter Transpose");
	printf("\nRows \tColumns \tValues");
	for(i=0;i<n;i++)
	{
		printf("\n%d \t%d \t%d",b[i][0],b[i][1],b[i][2]);
	}
}

void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;
	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	k=1;
	
	n=b1[0][2];
	n=b1[0][2];
	for(i=0;i<b1[0][1];i++)
	for(j=1;j<=n;j++)
	{
		if(i==b1[j][1])
		{
			b2[k][0]=i;
			b2[k][1]=b1[j][0];
			b2[k][2]=b1[j][2];
			k++;
		}
	}
}

