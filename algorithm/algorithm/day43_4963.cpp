#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> tree[55][55];
int c[55][55];
int c_index;
void dfs(int x, int y)
{
	if (c[x][y] != 0)return;
	c[x][y] = c_index;

	for (int i = 0; i < tree[x][y].size(); i++)
	{
		int a = tree[x][y][i].first;
		int b = tree[x][y][i].second;
		dfs(a, b);
	}
}
int main(void)
{
	int w, h;

	while (1)
	{
		c_index = 1;
		for (int i = 0; i < 55; i++)
		{
			for (int j = 0; j < 55; j++)
			{
				tree[i][j].clear();
				c[i][j] = 0;

			}
		}


		int arr[51][51] = { 0, };
		cin >> w >> h;
		if (w == 0 && h == 0)break;
		vector<pair<int, int>> v;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
				{
					v.push_back(pair<int, int>(i, j));
				}
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			int x = v[i].first, y = v[i].second;

			for (int a = -1; a < 2; a++)
			{
				if (x + a < 0)continue;
				if (x + a >= h)continue;
				for (int b = -1; b < 2; b++)
				{
					if (y + b < 0)continue;
					if (y + b >= w)continue;

					if (arr[x + a][y + b] == 1)
					{
						tree[x][y].push_back(pair<int, int>(x + a, y + b));
						tree[x + a][y + b].push_back(pair<int, int>(x, y));
					}
				}
			}

		}

		for (int i = 0; i < v.size(); i++)
		{
			int x = v[i].first, y = v[i].second;
			if (c[x][y] == 0)
			{
				dfs(x, y);
				c_index++;

			}


		}
		printf("%d\n", c_index - 1);
	}
}