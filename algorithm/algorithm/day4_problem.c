
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

bool compare(string a, string b)
{
    if (a.length() == b.length())
        return a < b;

    else
        return a.length() < b.length();


}

int main()
{
    int n;
    cin >> n;
    string c[200001];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c, c + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            if (c[i] != c[i + 1])
                cout << c[i] << "\n";

        }
        else
            cout << c[i] << "\n";
    }
    return 0;
}