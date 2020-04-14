#include<iostream>

using namespace std;

int main()
{
	int i, j, min, min_index,temp;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	
	for (i = 0; i < 9; i++)
	{
		min = 11;
		for (j = i; j < 10; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i];

	return 0;
}