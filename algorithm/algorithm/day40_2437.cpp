#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int arr[1001];

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + n);



}