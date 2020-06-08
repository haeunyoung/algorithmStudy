#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int w,h;

	while (1)
	{
		int arr[51][51] = {0,};
		cin >> w >> h;
		if (w == 0 && h == 0)break;
		vector<pair<int, int>> v;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
				{
					v.push_back(pair<int,int>(i, j));
				}
			}
		}
		int land_index = 1;
		int land[51][51] = { 0, };
		for (int i = 0; i < v.size(); i++)
		{
			int x = v[i].first, y = v[i].second;
			if (land[x][y] == 0)
			{
				for (int a = -1; a < 2; a++)
				{
					if (x + a < 0)continue;
					if (x + a >= h)continue;
					for (int b = -1; b < 2; b++)
					{
						if (y + b < 0)continue;
						if (y + b >= w)continue;

						if (land[x + a][y + b] != 0)
						{
							land[x][y] = land[x + a][y + b];
							a = 2;
							b = 2;
						}
					}
				}
				if (land[x][y] == 0)
				{
					land[x][y] = land_index;
					land_index++;
				}

			}
		}
		for (int i = v.size()-1; i >=0; i--)
		{
			int x = v[i].first, y = v[i].second;
			if (land[x][y] != 0)
			{
				for (int a = -1; a < 2; a++)
				{
					if (y + a < 0)continue;
					if (y + a >= w)continue;
					for (int b = -1; b < 2; b++)
					{
						if (x + b < 0)continue;
						if (x + b >= h)continue;

						if (land[x + b][y + a] != 0)
						{
							if (land[x + b][y + a] < land[x][y])
								land[x][y] = land[x + b][y + a];
						}
					}
				}

			}
		}
		int max = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (max < land[i][j])
					max = land[i][j];
			}
		}
		printf("%d\n",max);


	}
}