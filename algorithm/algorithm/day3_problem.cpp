#include<iostream>

using namespace std;

void main()
{
	int n;
	int a[50] = { 0, };
	int b[50] = { 0, };

	cout << "type number of array: " << endl;
	cin >> n;

	cout << "type A array :";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << "type B array :";
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	int b_index[50] = { 0, };
	int a_index[50] = { 0, };
	int new_a[50] = { 0, };
	int temp_b[50] = { 0, };
  
	int temp, max, max_index;
	memcpy(temp_b, b, n * sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		max = 0;
		for (int j = i; j < n; j++)
		{
			if (max < temp_b[j])
			{
				max = temp_b[j];
				max_index = j;
			}
		}
		temp = temp_b[max_index];
		temp_b[max_index] = temp_b[i];
		temp_b[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (temp_b[i] == b[j])
				b_index[i] = j;
		}
	}

	int min,min_index;
	for (int i = 0; i < n; i++)
	{
		min= 999;
		for (int j = i; j < n; j++)
		{
			if (min >a[j])
			{
				min = a[j];
				min_index = j;
			}
		}
	
		temp = a[min_index];
		a[min_index] = a[i];
		a[i] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		new_a[b_index[i]] = a[i];
	}
	cout << "new a array: " ;
	for (int i = 0; i < n; i++)
	{
		cout<<new_a[i];
	}
	cout << endl;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += b[i] * new_a[i];
	}

	cout << "miniest sum : " << sum;
}