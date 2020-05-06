#include<iostream>
#include<stdio.h>

using namespace std;
int t[1002];
int n;

int fibonacci(int i)
{
    if (i == 1)return 1;
    if (i == 2)return 3;
    if (t[i] != 0) return t[i];
    return t[i] = (2*fibonacci(i - 2) + fibonacci(i - 1) )% 10007;

}
int main()
{
    
    cin >> n;

    printf("%d\n",fibonacci(n));
}