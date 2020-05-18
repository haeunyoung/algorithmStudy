#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
vector<pair<float, float>> v;
float xy[101][2];
int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b)set[b] = a;
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
	float distance;

	Edge(int a, int b, float distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;

	}
	bool operator <(Edge& edge)
	{
		return this->distance < edge.distance;
	}
};
float distance(int i, int j)
{
	float d;
	return d = sqrt(pow((xy[i][0] - xy[j][0]), 2) + pow((xy[i][1] - xy[j][1]), 2));
}
int main(void)
{
	int n;
	cin >> n;
	float x, y;
	for (int i = 0; i < n; i++)
	{
		scanf("%f %f", &xy[i][0], &xy[i][1]);
	}
	vector<Edge> star;
	for (int i = 0; i < n; i++)//간선 정보를 저장 
	{
		for (int j = i + 1; j < n; j++)
		{
			float dis = distance(i, j);
			star.push_back(Edge(i, j, dis));
		}
	}

	sort(star.begin(), star.end());

	int set[101];
	for (int i = 0; i < n; i++)
		set[i] = i;

	float sum = 0;
	for (int i = 0; i < star.size(); i++)
	{
		if (!find(set, star[i].node[0], star[i].node[1]))
		{
			sum += star[i].distance;
			unionParent(set, star[i].node[0], star[i].node[1]);
		}
	}

	printf("%.2f\n", sum);
}