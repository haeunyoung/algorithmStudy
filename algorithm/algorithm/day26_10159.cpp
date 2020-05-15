#include<stdio.h>
int number;
int m;
int a[103][103];
void floy() {
	for (int k = 1; k <= number; k++)
	{
		for (int i = 1; i <=number; i++)
		{
			if (k == i)continue;
			for (int j = 1; j <=number; j++)
			{
				if (k == j)continue;
				if (i == j)continue;

				if (a[i][k] + a[k][j] == 2)
					a[i][j] = 1;
			}
		}
	}
	int count=0;
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <=number; j++)
		{
			if (a[i][j] == 1)a[j][i] = 1; 
			if (i == j)a[i][j] = 1;
		}
	}
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= number; j++)
		{
			if (a[i][j] == 0) count++;
		}
		printf("%d\n", count);
		count = 0;
	}

}
int main()
{
	scanf("%d", &number);
	scanf("%d", &m);
	int temp1, temp2;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		a[temp1][temp2] = 1;

	}

	floy();
	
	return 0;
}