#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<stdio.h>

using namespace std;

int main()
{
	int n, num;
	queue<int> q;
	char str[10];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);


		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &num);
			q.push(num);
		}
		else if (strcmp(str, "pop") == 0)
		{
			if (!q.empty())
			{
				printf("%d\n", q.front());
				q.pop();

			}
			else
				printf("%d\n", -1);

		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", q.size());
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", q.empty());
		}

		else if (strcmp(str, "front") == 0)
		{
			if (!q.empty())
				printf("%d\n", q.front());
			else
				printf("%d\n", -1);
		}
		else if (strcmp(str, "back") == 0)
		{
			if (!q.empty())
				printf("%d\n", q.back());
			else
				printf("%d\n", -1);
		}
	}

	return 0;
}