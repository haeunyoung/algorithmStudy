#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
	queue<int> q;
	string s;
	cin >> s;
	int last = -1;
	int minus_index[50] = { 0. };
	int arr[52] = { 0, };
	int temp[5] = { 0, };
	int temp_index = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			
		}
		else if (s[i] == '+')
		{
          
		}
		else
		{
			temp[temp_index] = (int)s[i];
			temp_index++;
		}

	}
}