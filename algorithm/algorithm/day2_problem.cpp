#include<iostream>

using namespace std;

void main()
{
	int arr[12] = { 0, };
	cout << "type 11 numbers: "<<endl;
		for (int i = 0; i < 11; i++)
		{
			cin >> arr[i];
		}

		int temp, min, min_index,i,j;
		
		for (i = 0; i < 10; i++)
		{   
			min = 999;
			for (j = i; j < 11; j++)
			{
				if (min>arr[j])
				{
					min = arr[j];
					min_index = j;
				}

			}
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;

		}
		cout << "result"<<endl;
		for (int num = 0; num < 11; num++)
			cout << arr[num] << endl;
			
}