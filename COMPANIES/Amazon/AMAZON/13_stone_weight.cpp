#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> maxheap;
    for (int i = 0; i < stones.size(); i++)
    {
        maxheap.push(stones[i]);
    }
    while (maxheap.size() > 1)
    {
        int first = maxheap.top();
        maxheap.pop();
        int second = maxheap.top();
        maxheap.pop();
        int r = first - second;
        if (r != 0)
        {
            maxheap.push(r);
        }
    }
    return maxheap.empty() ? 0 : maxheap.top();
}

int main()
{
    
}