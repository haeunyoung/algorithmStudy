#include<iostream>
#include<stdio.h>
using namespace std;

typedef struct{
	int x;
	int linkIndex[2];

} node;
node tree[125750];
void makeStruct(int a)
{

	tree[a].linkIndex[0] = a + 1;
	tree[a].linkIndex[1] = a + 2;
}

int main(void)
{
	int n;
	cin >> n;
	
	int num = (n * (n + 1)) / 2;
	for (int i = 0; i < num; i++)
		scanf("%d", &tree[i].x);
	//두개의 자식 연결 
	for (int i = 0; i < num - n; i++)
	{
		makeStruct(i);

	}

}