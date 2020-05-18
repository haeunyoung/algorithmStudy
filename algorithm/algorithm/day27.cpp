#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];// 방문처리
bool finished[MAX];//현재 dfs가 끝났는지 
vector<int> a[MAX]; //연결 노드 나타내기 위해서
vector<vector<int>> SCC; // 이중 배열로 나타냄
stack<int> s;

//총 정점의 개수만큼 실행
int dfs(int x)
{
	d[x] = ++id;
	s.push(x);// 스택에 자기 자신을 넣음

	int parent = d[x];// 부모 자기 자신 넣기 
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];

		// 방문하지 않았다면 
		if (d[y] == 0)parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
	//부모 노드가 자기 자신일 경우
		vector<int> scc;
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x)break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main(void)
{
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++)
		if (d[i] == 0)dfs(i);

	printf("SCC의 개수: %d\n", SCC.size());

	for (int i = 0; i < SCC.size(); i++)
	{
		printf("%d번째 SCC: ", i + 1);
		for (int j = 0; j < SCC[i].size(); j++)
			printf("%d ", SCC[i][j]);

		printf("\n");
	}
	return 0;
}