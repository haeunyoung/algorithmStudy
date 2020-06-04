#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n>>k;
	int arr[500001];

	for (int i = 0; i < n; i++)
		scanf("%1d", &arr[i]);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
