#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int main(void)
{
	queue<int> q;
	string s;
	cin >> s;
	//int last = -1;
	//int minus_index[50] = { 0. };
	int arr[105] = { 0, };
	int arr_index = 0;
	int temp[5] = { 0, };
	int temp_index = 0;
	bool minus = false;
	int minus_index = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			int num = 0;
			for (int j = 0; j < temp_index; j++)
			{
				num += temp[j] * pow(10, temp_index - 1 - j);
			}
			arr[arr_index] = num;
			temp_index = 0;
			for (int i = 0; i < 5; i++)
				temp[i] = 0;
			arr_index++;
			if (minus == false)
			{
				minus_index = arr_index;
				arr[arr_index] = -1;
				arr_index++;
				minus = true;
			}
			continue;


		}
		else if (s[i] == '+')
		{
			int num = 0;
			for (int j = 0; j < temp_index; j++)
			{
				num += temp[j] * pow(10, temp_index - 1 - j);
			}
			arr[arr_index] = num;
			temp_index = 0;
			for (int i = 0; i < 5; i++)
				temp[i] = 0;
			arr_index++;
			continue;
		}
		else
		{
			temp[temp_index] = s[i] - '0';
			temp_index++;
		}
		if (i == s.size() - 1)
		{
			int num = 0;
			for (int j = 0; j < temp_index; j++)
			{
				num += temp[j] * pow(10, temp_index - 1 - j);
			}
			arr[arr_index] = num;
			temp_index = 0;
			for (int i = 0; i < 5; i++)
				temp[i] = 0;
			arr_index++;
		}
	}
	int result = 0;
	if (minus_index == 0)
	{
		for (int i = 0; i < arr_index; i++)
		{
			result += arr[i];
		}
	}
	else
	{
		for (int i = 0; i < minus_index; i++)
		{
			result += arr[i];
		}

		for (int i = minus_index + 1; i < arr_index; i++)
		{
			result -= arr[i];
		}

	}

	printf("%d\n", result);
}