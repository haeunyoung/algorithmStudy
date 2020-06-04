#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	string s[1001];
	char answer[51];
	int haming = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	char arr[4] = { 'A','C','G','T' };
	for (int i = 0; i < m; i++)
	{
		int max = -1,max_index=0;
		int count[4] = { 0, };
		for (int j = 0; j < n; j++)
		{
			if (s[j][i] == 'A')
				count[0]++;
			else if (s[j][i] == 'C')
				count[1]++;
			else if (s[j][i] == 'G')
				count[2]++;
			else
				count[3]++;

		}
		for (int z = 0; z < 4; z++)
		{
			if (count[z] >max)
			{
				max = count[z];
				max_index = z;
			}
		}
		answer[i] = arr[max_index];

		for (int z = 0; z < 4; z++)
		{
			if (z!=max_index)
			{
				haming+=count[z];
			}
		}

	}

	for (int i = 0; i < m; i++)
		printf("%c", answer[i]);
	printf("\n%d\n", haming);

}