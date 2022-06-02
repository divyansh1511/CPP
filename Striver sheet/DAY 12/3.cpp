#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a , vector<int> &b , int c){
    sort(a.begin() , a.end() , greater<int>());
    sort(b.begin() , b.end() , greater<int>());
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < c; i++)
    {
        pq.push(a[i]+b[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (i != j)
            {
                if (a[i]+b[j] >= pq.top())
                {
                    pq.pop();
                    pq.push(a[i]+b[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin() , ans.end() , greater<int>());
    return ans;
}

int main(){

}