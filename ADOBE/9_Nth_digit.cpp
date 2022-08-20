#include <bits/stdc++.h>
using namespace std;

int findNthdigit(int n)
{
    long base = 9, digit = 1;
    while (n - base * digit > 0)
    {
        n -= base * digit;
        base *= 10;
        digit++;
    }

    int index = n % digit;
    if (index == 0)
    {
        index = digit;
    }
    long num = 1;
    for (int i = 1; i < digit; i++)
    {
        num *= 10;
    }
    num += (index == digit) ? n / digit - 1 : n / digit;

    for (int i = index; i < digit; i++)
    {
        num /= 10;
    }
    return num % 10;
}

int main()
{
    
}