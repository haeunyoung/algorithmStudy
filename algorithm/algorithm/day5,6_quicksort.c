#include<stdio.h>

int node = 10;
int data[] = { 1,10,5,8,7,6,4,3,2,9 };

void show()
{
	int i;
	for (i = 0; i < node; i++)
		printf("%d ", data[i]);
}

void quickSort(int* data, int start, int end)
{
	if (start >= end)// ���Ұ� 1���� ��� 
	{
		return;
	}
	int key = start;//pivot���� ù��° ����
	int i = start + 1, j = end, temp;

	while (i <= j)//������������ �ݺ� 
	{
		while (data[i] >= data[key] && i <= end)//Ű ������ ū���� ������ ����
		{
			i++;
		}
		while (j > start && data[key]>= data[j])//Ű ������ ���� ���� ������ ���� 
		{
			j--;
		}
		if (i > j) {//���� ������ ���¸� Ű �� ��ü
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else//�������� ���� 
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	

	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}
int main(void)
{
	quickSort(data, 0, node - 1);
	show();
	return 0;
}