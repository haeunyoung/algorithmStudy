#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}
void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a > b) set[a] = b;
	else set[b] = a;
}
int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b)return 1;
	else return 0;
}

class Node {
public:
	int point[2],distance;

	Node(int a, int b, int distance)
	{
		this->point[0] = a;
		this->point[1] = b;
		this->distance = distance;
	}
	bool operator<(Node& node)
	{
		return this->distance < node.distance;
	}

};


int main(void)
{
	int n;
	cin >> n;
	vector<Node> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			scanf("%d", &temp);
			if (i == j) continue;
			v.push_back(Node(i, j, temp));
		}
	}

	sort(v.begin(), v.end());

	int min_distance = 0;
	int set[21] = {0,};
	for (int i = 0; i < n; i++)
		set[i] = i;

	for (int i = 0; i < v.size(); i++)
	{
		if (!find(set, v[i].point[0], v[i].point[1]))
		{
			unionParent(set, v[i].point[0], v[i].point[1]);
			min_distance += v[i].distance;
		}
	}
	int a = set[0];
	for (int i = 1; i < n; i++)
	{
		if (a != set[i])
		{
			min_distance = -1;
			break;
		}
	}
	printf("%d\n", min_distance);
}