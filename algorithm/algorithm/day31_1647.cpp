#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n, m;
int getParent(int set[], int x)
{
	if (set[x] == x) return x;
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
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator<(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};
int main(void)
{
	cin >> n >> m;

	vector<Edge> v;
	int h1, h2, k;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &h1, &h2, &k);
		v.push_back(Edge(h1, h2, k));
	}
	sort(v.begin(), v.end());

	int set[n+1];
	for (int i = 1; i <= n; i++)
	{
		set[i] = i;
	}
	int sum = 0;
	int last_k;
	for (int i = 0; i < v.size(); i++)
	{
		if (!find(set, v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			last_k = v[i].distance;
			unionParent(set, v[i].node[0], v[i].node[1]);
		}
	}
     
	printf("%d\n", sum-last_k);
}