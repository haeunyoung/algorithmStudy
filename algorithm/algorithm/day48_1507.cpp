#include<iostream>

using namespace std;


int main(void)
{
	int n;
	cin >> n;

	int arr[21][21];
	int d[21][21];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			d[i][j] = arr[i][j];
		}
	}
	int distance = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)continue;
			for (int z = 0; z < n; z++)
			{
				if (i == z)continue;
				if (arr[j][z] > arr[j][i] + arr[i][z])
				{
					distance = -1;
				}
				else if (arr[j][z] == arr[j][i] + arr[i][z])
					d[j][z] = 0;

			}
		}
	}
	if (distance == -1)
		printf("-1\n");
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				distance += d[i][j];
			}
		}
		//i->j j->i 둘다 계산 했으니 2로 나누어 준다. 
		printf("%d\n", distance / 2);

	}
}