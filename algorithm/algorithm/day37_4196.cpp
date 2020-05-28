#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 100001
using namespace std;
vector<int> a[MAX];
//방문기록
int id, d[MAX];
bool finished[MAX];
vector<vector<int>> SCC;
stack<int> s;
bool inDegree[MAX];
int group[MAX];

int dfs(int x)
{
	d[x] = ++id;
	s.push(x);

	int result = d[x];

	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];

		if (d[y] == 0) result = min(result, dfs(y));
		else if (!finished[y]) result = min(result, d[y]);
	}

	if (result == d[x])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			finished[t] = true;
			if (t == x) break;
		}

		SCC.push_back(scc);
	}
	return result;

}
int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, 0);
		fill(inDegree, inDegree + MAX, false);
		fill(group, group + MAX, 0);
		id = 0;
		int n, m;
		int count = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++)
			a[i].clear();

		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			a[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
			if (d[i] == 0)dfs(i);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < a[i].size(); j++)
			{
				int y = a[i][j];

				if (group[i] != group[y])
				{
					inDegree[group[y]] = true;
				}
			}
		}

		for (int i = 1; i <= SCC.size(); i++)
		{
			if (inDegree[i] == 0) count++;
		}
		printf("%d\n", count);

	}
}