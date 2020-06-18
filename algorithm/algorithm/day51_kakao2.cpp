#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    char temp_answer[1000000];
    int arr[30] = { 0, };
    int a[1000100];
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    int a_index = n;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[a_index] = i;
            a_index++;
            a[a_index] = j;
            a_index++;
        }
    }
    int start = n;
    int end = a_index;
    int num = 2;
    while (a_index <= m * t)
    {
        for (int i = start; i < end; i += num)
        {

            for (int j = 0; j < n; j++)
            {
                for (int z = i; z < i + num; z++)
                {
                    a[a_index] = a[z];
                    a_index++;
                }
                a[a_index] = j;
                a_index++;

            }
        }
        num++;
        start = end;
        end = a_index;

    }


    for (int i = 1; i <= t; i++)
    {
        int temp = a[m * i - (m - p) - 1];
        if (temp == 10) {
            answer.append("A");
        }
        else if (temp == 11) answer.append("B");
        else if (temp == 12) answer.append("C");
        else if (temp == 13) answer.append("D");
        else if (temp == 14) answer.append("E");
        else if (temp == 15) answer.append("F");
        else
            answer += to_string(temp);
        //printf("temp %d\n", temp);
    }

    return answer;
}