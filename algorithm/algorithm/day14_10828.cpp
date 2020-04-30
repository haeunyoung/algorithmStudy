/*#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<stdio.h>

using namespace std;

int main()
{
	int n, num;
	stack<int> s;
	char str[10];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);


		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &num);
			s.push(num);
		}
		else if (strcmp(str, "pop") == 0)
		{
			if (!s.empty())
			{
				printf("%d\n", s.top());
				s.pop();

			}
			else
				printf("%d\n", -1);

		}
		else if (strcmp(str, "size") == 0)
		{
			printf("%d\n", s.size());
		}
		else if (strcmp(str, "empty") == 0)
		{
			printf("%d\n", s.empty());
		}

		else if (strcmp(str, "top") == 0)
		{
			if (!s.empty())
				printf("%d\n", s.top());
			else
				printf("%d\n", -1);
		}
	}

	return 0;
}

*/

#include <iostream>
#include <stack>

using namespace std;


int main()
{
	int n;
	int inputNum;
	char com[10];
	stack<int> s;


	scanf("%d", &n);

	while (n != 0) {
		scanf("%s", com);

		if (strcmp(com, "push") == 0) {
			scanf("%d", &inputNum);

			s.push(inputNum);
		}
		else if (strcmp(com, "pop") == 0) {
			s.pop();
			cout << s.top() << endl;
		}
		else if (strcmp(com, "size") == 0) {
			cout << s.size() << endl;
		}
		else if (strcmp(com, "empty") == 0) {
			if (!s.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if (strcmp(com, "top") == 0) {
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}

		n--;
	}



	return 0;
}