#include<stdio.h>

int main()
{
	int n;
	int temp;
	int count[10002] = { 0, };

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		count[temp]++;
	}
	

		for (int i = 1; i < 10002; i++)
		{
			if (count[i] != 0)
			{
				for (int j = 0; j < count[i]; j++)
					printf("%d\n", i);
			}
		}
	return 0;

}