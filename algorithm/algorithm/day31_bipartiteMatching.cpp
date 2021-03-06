#include<iostream>
#include<vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX];// 어디랑 연결 되있는지
bool c[MAX];
int n = 3,m, s;
//매칭에 성공한 경우 true 실패한 경우 false
bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];

		if (c[t])continue;
		c[t] = true;

		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	return false;
}
int main(void)
{
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);

	a[2].push_back(1);

	a[3].push_back(2);
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}

	printf("%d개의 매칭이 일어났습니다.\n", count);

	for (int i = 1; i <= 100; i++)
	{
		if (d[i] != 0)
		{
			printf("%d -> %d\n", d[i], i);
		}
	}
}