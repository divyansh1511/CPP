#include <bits/stdc++.h>
using namespace std;

int maxprofit(vector<int> prices)
{
    int sum = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i] > prices[i + 1])
        {
            continue;
        }
        else
        {
            sum += (prices[i + 1] - prices[i]);
        }
    }
    return sum;
}

int main()
{
    
}