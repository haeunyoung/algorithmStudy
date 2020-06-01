#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void testcase()
{
	vector<pair<int, int>> v;
	int n;
	cin >> n;
	bool success[100001];

	for (int i = 0; i < 100001; i++)
		success[i] = true;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v.push_back(pair<int, int>(x, y));
	}

	sort(v.begin(), v.end());

	int num = 1;
	int max_prior = v[0].second;
	for (int i = 1; i < v.size(); i++)
	{
		if (max_prior > v[i].second)
		{
			num++;
			max_prior = v[i].second;
		}

	}

	printf("%d\n", num);
}
int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
		testcase();
}