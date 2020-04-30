#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int main()
{
	int num[3];
	char c[3];
	int sequence[3];
	char enter;

	for (int i = 0; i < 3; i++)
		scanf("%d", &num[i]);

	scanf("%c", &enter);

	for (int i = 0; i < 3; i++)
	{
		scanf("%c", &c[i]);
		if (c[i] == 'A')
		{
			sequence[i] = 0;
		}
		else if (c[i] == 'B')
		{
			sequence[i] = 1;
		}
		else
		{
			sequence[i] = 2;
		}

	}

	sort(num, num + 3);
	for (int i = 0; i < 3; i++)
		printf("%d ", num[sequence[i]]);
	return 0;
}