#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;;
int number = 7;
int c[7];
vector<int> a[8];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	c[start] = true;//�湮���

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i++) //����� ���� ť�� ����ֱ� 
		{
			int y = a[x][i];
			if (!c[y]) { //�湮����� ���ٸ� 
				q.push(y);
				c[y] = true;
			}
		}
	}

}
int testcase(int n)
{


}


int main()
{
	int t,index=0;
	int n[1002];
	do {
			scanf("%d", &n[index]);
		t = n[index];
		index++;
	} while (t != 0);
	
	for (int i = 0; i < t; i++)
		printf("%lld\n", testcase(n[i]));
	return 0;
}
