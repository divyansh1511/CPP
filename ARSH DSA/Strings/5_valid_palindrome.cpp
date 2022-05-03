#include <bits/stdc++.h>
using namespace std;

bool validPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            int i1 = i + 1, j1 = j, i2 = i, j2 = j - 1;
            while (i1 < j1 && s[i1] == s[j1])
            {
                i1++;
                j1--;
            }
            while (i2 < j2 && s[i2] == s[j2])
            {
                i2++;
                j2--;
            }
            return i1 >= j1 || i2 >= j2;
        }
    }
    return true;
}

int main()
{
}