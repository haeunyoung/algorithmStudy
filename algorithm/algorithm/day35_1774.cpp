#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
int xy[1001][2];
double makedistance(int a, int b)
{
	double d = sqrt(pow((xy[a][0] - xy[b][0]), 2) + pow((xy[a][1] - xy[b][1]), 2));
	return d;
}
int getParent(int set[], int x)
{
	if (set[x] == x)return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	double distance;
	Edge(int a, int b, double distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge& edge)
	{
		return this->distance < edge.distance;
	}
};

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<Edge> v;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &xy[i][0], &xy[i][1]);

	int connect[1001][2];
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &connect[i][0], &connect[i][1]);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double dis = makedistance(i, j);
			v.push_back(Edge(i, j, dis));
		}
	}

	sort(v.begin(), v.end());

	int set[n + 1];

	for (int i = 1; i <= n; i++)
	{
		set[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		unionParent(set, connect[i][0], connect[i][1]);
	}
	double sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (!find(set, v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			unionParent(set, v[i].node[0], v[i].node[1]);
		}
	}
	printf("%.2lf", sum);
}