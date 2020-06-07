#include<iostream>
#include<vector>

using namespace std;

int getParent(int set[], int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}
class Weight
{
public:
	int node[2];
	int distance;
	Weight(int a, int b, int distance)
	{
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

};

int main(void)
{
	int n=1, m=1;

	while (n != 0 && m != 0)
	{
		cin >> n >> m;
		vector<Weight> v;
		int set[100001];
		for (int i = 1; i <=n; i++)
			set[i] = i;

		for (int i = 0; i < m; i++)
		{
			int c;
			scanf_s("%c", &c);
			
			if (c == '!')
			{
				int exc1, exc2, exc3;
				scanf_s("%d %d %d", &exc1, &exc2, &exc3);
				v.push_back(Weight(exc1, exc2, exc3));
				v.push_back(Weight(exc2, exc1, -exc3));
				unionParent(set, exc1, exc2);
			}
			else
			{
				int q1, q2;
				scanf_s("%d %d", &q1, &q2);
				int answer=find(set, q1, q2);
				if (answer == 0)
					printf("UNKNOWN\n");
				else {
					
					int check,big;
					int reverse = 0;
					if (q1 < q2)
					{
						check = q1;
						big = q2;
					}
					else if (q1 > q2)
					{
						check = q2;
						big = q1;
						reverse = 1;
					}
					
					int arr[1000001];
					int arr_index = 0;
					
					for (int j = 1; j <=big; j++)
					{
						if (set[j] == check)
						{
							arr[arr_index] = j;
							arr_index++;
						}

					}
					int sum = 0;
					
					for (int z = 0; z <arr_index-1; z++)
					{
						for (int j = 0; j < v.size(); j++)
						{
							if (v[j].node[0] == arr[z] && v[j].node[1] == arr[z + 1])
							{
								sum += v[j].distance;
								break;
							}
						}
					}
					
					if (reverse == 1)
						printf("%d\n", -sum);
					else
						printf("%d\n", sum);
						
				}
				
			}
			
		}
		
	}
}