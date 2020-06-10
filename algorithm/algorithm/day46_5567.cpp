#include<iostream>
#include<vector>

using namespace std;
int n, m;
vector<int> v[501];
int c[501];
int answer;

void bfs(int start,int index)
{
	c[start] = true;
	
		for (int i = 0; i < v[start].size(); i++)
		{
				int next = v[start][i];
				if (index < 2)
				{
					if (c[next] != true)
					{
						answer++;

					}
					bfs(next, index + 1);
				}
				else break;
		
		}



}

int main(void)
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1,0);
	printf("%d\n", answer);
}