#include<stdio.h>

void main()
{
    int number;
    printf("type the number:");
    scanf_s("%d", &number);

    //int형 자리수 구하기
    int count = 0;
    int num = number;
    int arr[10] = { 0, };
    do
    {
        arr[count] = num % 10;
        num = num / 10;
        count++;
    } while (num > 0);

    int con;
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] < arr[j])
            {
                con = arr[i];
                arr[i] = arr[j];
                arr[j] = con;

            }
        }
    }

    for (int i = 0; i < count; i++)
        printf("%d", arr[i]);
}