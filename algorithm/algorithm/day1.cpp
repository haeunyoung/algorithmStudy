#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int number;
    cout << "type the number(c++) : ";
    cin >> number;
 

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
    cout << arr[i];

    return 0;
    
}