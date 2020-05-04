#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;

stack<char> good;

int testcase(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (good.empty())
		{
			good.push(s[i]);
			continue;
		}
		if (good.top() == s[i])
		{
			good.pop();
		}
		else {
			good.push(s[i]);
		}
	}
	int state = good.empty();
	while (!good.empty()) {
		good.pop();
	}
	return state;

}
int main()
{
	int n;
	string str[102];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> str[i];
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += testcase(str[i]);

	printf("%d\n", sum);
	return 0;
}