#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[100][10];
	int temp_a[100][10];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}


	int w1 = 0, w2 = 0, w3 = 0;
	int w[3][2];
	int w_num = 0;
	int min_index = 100000;
	memcpy(temp_a, a, sizeof(a));
	for (int aw = 0; aw < n; aw++)
	{
		for (int bw = 0; bw < m; bw++)
		{
			if (temp_a[aw][bw] != 0)
				continue;
			else
			{

				if (w_num == 0)
				{
					w[0][0] = aw;
					w[0][1] = bw;// 벽 index 저장
					temp_a[aw][bw] = 1;

					w_num++;
					continue;

				}
				else if (w_num == 1)
				{
					w[1][0] = aw;
					w[1][1] = bw;// 벽 index 저장
					temp_a[aw][bw] = 1;
					w_num++;
					continue;

				}
				else if (w_num == 2)
				{//2 바이러스 
					w[2][0] = aw;
					w[2][1] = bw;// 벽 index 저장
					temp_a[aw][bw] = 1;
					w_num = 0;
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							if (temp_a[i][j] == 2) {
								if ((i == 0) || (i == n - 1) || (j == 0) || (j == m - 1))
								{
									if (i == 0)
									{
										if (j == 0)
										{

											if (temp_a[i + 1][j] != 1)
												temp_a[i + 1][j] = 2;
											if (temp_a[i][j + 1] != 1)
												temp_a[i][j + 1] = 2;
										}
										else if (j == m - 1)
										{
											if (temp_a[i + 1][j] != 1)
												temp_a[i + 1][j] = 2;
											if (temp_a[i][j - 1] != 1)
												temp_a[i][j - 1] = 2;
										}
										else
										{
											if (temp_a[i + 1][j] != 1)
												temp_a[i + 1][j] = 2;
											if (temp_a[i][j - 1] != 1)
												temp_a[i][j - 1] = 2;
											if (temp_a[i][j + 1] != 1)
												temp_a[i][j + 1] = 2;
										}
									}

									if (i == n - 1)
									{
										if (j == 0)
										{

											if (temp_a[i - 1][j] != 1)
												temp_a[i - 1][j] = 2;
											if (temp_a[i][j + 1] != 1)
												temp_a[i][j + 1] = 2;
										}
										else if (j == m - 1)
										{
											if (temp_a[i - 1][j] != 1)
												temp_a[i - 1][j] = 2;
											if (temp_a[i][j - 1] != 1)
												temp_a[i][j - 1] = 2;
										}
										else
										{
											if (temp_a[i - 1][j] != 1)
												temp_a[i - 1][j] = 2;
											if (temp_a[i][j - 1] != 1)
												temp_a[i][j - 1] = 2;
											if (temp_a[i][j + 1] != 1)
												temp_a[i][j + 1] = 2;
										}
									}

									if (j == 0)
									{
										if ((i != 0) && (i != n - 1)) {
											if (temp_a[i - 1][j] != 1)
												temp_a[i - 1][j] = 2;
											if (temp_a[i][j + 1] != 1)
												temp_a[i][j + 1] = 2;
											if (temp_a[i + 1][j] != 1)
												temp_a[i + 1][j] = 2;
										}
									}

									if (j == m - 1)
									{
										if ((i != 0) && (i != n - 1)) {
											if (temp_a[i - 1][j] != 1)
												temp_a[i - 1][j] = 2;
											if (temp_a[i][j - 1] != 1)
												temp_a[i][j - 1] = 2;
											if (temp_a[i + 1][j] != 1)
												temp_a[i + 1][j] = 2;
										}
									}

								}
								else {
									if (temp_a[i - 1][j] != 1)
										temp_a[i - 1][j] = 2;
									if (temp_a[i + 1][j] != 1)
										temp_a[i + 1][j] = 2;
									if (temp_a[i][j - 1] != 1)
										temp_a[i][j - 1] = 2;
									if (temp_a[i][j + 1] != 1)
										temp_a[i][j + 1] = 2;
								}

							}
							else
								continue;


						}
					}

					int count = 0;
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							if (temp_a[i][j] == 0)
								count++;
						}
					}
					if (min_index > count)
						min_index = count;
					memcpy(temp_a, a, sizeof(a));
					

				}

			}
		}
	}

	
	cout << min_index << '\n';
}
