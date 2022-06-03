#include <bits/stdc++.h>
using namespace std;

int palindromicPartition(string str)
{
    int cut[str.length()];
    bool pal[str.length()][str.length()];
    memset(pal, false, sizeof(pal));
    for (int i = 0; i < str.length(); i++)
    {
        int minicut = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j < 2 || pal[j + 1][i - 1]))
            {
                pal[j][i] = true;
                minicut = min(minicut, j == 0 ? 0 : (cut[j - 1] + 1));
            }
        }
        cut[i] = minicut;
    }
    return cut[str.length() - 1];
}

int main()
{
}