#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	string s[1001];
	int hamming[1001] = { 0, };

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	
	sort(s, s + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int z = 0; z < m; z++)
			{
				if (s[i][z] != s[j][z])
				{
					hamming[i]++;
				}
	

			}

		}
	}

	int min = 100;
	int min_index;

	for (int i = 0; i < n; i++)
	{
		if (hamming[i] < min)
		{
			min_index = i;
			min = hamming[i];
		}
	}
	cout << s[min_index]<<"\n";
	cout << min << "\n";

}