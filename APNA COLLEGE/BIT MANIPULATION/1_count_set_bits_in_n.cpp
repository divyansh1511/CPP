#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    // Your logic here
    n++;
    int po2 = 2;
    int cnt = n / 2;
    while (po2 <= n)
    {
        int tp = n / po2;
        cnt += (tp / 2) * po2;
        cnt += (tp & 1) ? (n % po2) : 0;
        po2 <<= 1;
    }
    return cnt;
}

int main()
{
}