#include<iostream>
#include<algorithm>
using namespace std;
string c[51];

bool compare(string a, string b)
{
	int temp1 = 0, temp2 = 0;
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++) {
			if (a[i] - '0' < 10)
			{
				temp1 += a[i] - '0';
			}
		}

		for (int i = 0; i < b.length(); i++) {
			if (b[i] - '0' < 10)
			{
				temp2 += b[i] - '0';
			}
		}


		if (temp1 != temp2)
			return temp1 < temp2;

		else
			return a < b;
	}
	else
		return a.length() < b.length();
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n, compare);
	for (int i = 0; i < n; i++)
		cout << c[i] << "\n";
	return 0;
}