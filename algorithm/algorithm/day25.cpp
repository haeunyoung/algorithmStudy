#include<stdio.h>

const int number = 4;
int IMF = 1000000000;

int a[4][4] = {
	{0,5,IMF,8},
	{7,0,9,IMF},
	{2,IMF,0,4},
	{IMF,IMF,3,0}
};

void floyWarshall() {
	int d[number][number];

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			d[i][j] = a[i][j];
		}
	}

	//k-거처가는 노드

	for (int k = 0; k < number; k++)
	{
		for (int i = 0; i < number; i++)
		{
			if (i == k)continue;
			for (int j = 0; j < number; j++)
			{
				if (i == k)continue;
				if (i == j)continue;
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	//
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			printf("%3d", d[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	floyWarshall();
}