#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int getParent(int parent[], int x)
{
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return 1;
	else return 0;
}
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator<(Edge& edge)
	{
		return this->distance < edge.distance;
	}

};
int main()
{
	int point = 7;
	int line = 11;
	vector<Edge> v;
	
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62)); 
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end());

	int set[8];
	for (int i = 1; i <=point; i++)
	{
		set[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (!findParent(set, v[i].node[0], v[i].node[1]))
		{
			sum += v[i].distance;
			unionParent(set, v[i].node[0], v[i].node[1]);
		}
	}
	printf("%d\n", sum);

	return 0;

}