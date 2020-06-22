#include<iostream>

using namespace std;
int num;
int arr[101];
int d[101][2];
int dp(int index){

	
	d[index + 1][0] = arr[index] + arr[index + 1];
	
	d[index + 1][1] = arr[index] -arr[index + 1];

}
int main(void)
{
	cin >> num;
	int temp;
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &temp);
		arr[i] = temp;

	}
	dp(0);

	dp(1);
	dp(2);

}