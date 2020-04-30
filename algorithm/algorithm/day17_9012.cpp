#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

int main()
{
	int n;
	int a = 0, b = 0;
	cin >> n;
	char c[10000][55];
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	
	for(int i=0;i<n;i++)
	{
		int ab[30][2] = { 0, };
		a = 0, b = 0;
		for (int j = 0; j < strlen(c); j++)
		{

			if (c[i][j] == '(')
			{

				ab[a][0] = 1;
				a++;
			}
			else
			{
				if ((ab[b][0] != 1) && (j != strlen(c[i]) - 1))
					a += 1;
				ab[b][1] = 1;
				b++;



			}
		}


		int yes = 0;
		int temp = 0;
		if (a < b)
			temp = b;
		else
			temp = a;

		for (int i = 0; i < temp; i++)
		{
			if ((ab[i][0] == 0) || (ab[i][1] == 0))
			{
				printf("NO\n");
				break;
			}
			else
				yes++;
		}
		if (yes == temp)
			printf("YES\n");


	}

	return 0;
}