#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int t, n;

typedef struct node
{
	long int x;
	long int y;
	long int distance_fes;

	vector<int> link;

}Distance;
long int calculate_dis(Distance a, Distance b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int bfs(Distance* d, int start)
{
	if (start == n)
	{
		if (d[start].distance_fes <= 1000)
			return 1;
		else return 0;
	}
	if (start < n)
	{
		for (int i = 0; i < d[start].link.size(); i++)
		{
			int linked = d[start].link[i];
			if (calculate_dis(d[start], d[linked]) <= 1000)
			{
				return bfs(d, linked);

			}

		}
	}
}
int testcase()
{
	cin >> n;
	Distance dis[200] = {0,};
	long int x, y;

	for (int i = 0; i < n + 2; i++)
	{
		cin >> x >> y;
		dis[i].x = x;
		dis[i].y = y;
	}

	for (int i = 0; i < n + 1; i++)
	{
		dis[i].distance_fes = calculate_dis(dis[n + 1], dis[i]);
		for (int j = i + 1; j < n + 1; j++)
			dis[i].link.push_back(j);

	}

	return bfs(dis, 0);
}


int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int result = testcase();
		if (result == 0)
			printf("sad\n");
		else
			printf("happy\n");
	}

	return 0;
}