#include<iostream>
using namespace std;

int n, m;
int main(void)
{
	cin >> n >> m;

	int answer = (m - 1) + (n - 1) * m;

	printf("%d\n", answer);
}