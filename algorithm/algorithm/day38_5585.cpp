#include<iostream>
using namespace std;
int main(void)
{
	int money,count=0;
	cin >> money;
	money = 1000 - money;
	
	int arr[6] = { 500,100,50,10,5,1 };
	int i = 0;
	while (money != 0)
	{
		count += money / arr[i];
		money %= arr[i];
		i++;
	}

	printf("%d\n", count);
}
