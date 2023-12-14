#include<stdio.h>
#include<stdlib.h>

int main()
{
    int SIZE = 10;
    float a[SIZE][SIZE], x[SIZE];
    int n;
    printf("Enter the no of unknowns:");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			scanf("%f", &a[i][j]);
		}
	}
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==0)
        {
            exit(0);
        }
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                float ratio = a[j][i]/a[i][i];
                for(int k=1;k<=n+1;k++)
                {
                    a[j][k] = a[j][k] - ratio*a[i][k];
                }
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        x[i] = a[i][n+1]/a[i][i];
    }
    printf("\nSolution:\n");
	for(int i=1;i<=n;i++)
	{
	    printf("x[%d] = %0.3f\n",i, x[i]);
	}
}