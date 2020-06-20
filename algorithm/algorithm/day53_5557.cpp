#include<iostream>

using namespace std;
int num;
int arr[101];
int dp(int index,int ex){

	if (ex == 0)
	{
		int t1 = -arr[index] + dp(index + 1, 0);
		int t2= -arr[index] + dp(index + 1, 1);
	}
	else
	{
		int t3 = arr[index] + dp(index + 1, 0);
		int t4 = arr[index] + dp(index + 1, 1);

	}


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
	dp(0,1);


}