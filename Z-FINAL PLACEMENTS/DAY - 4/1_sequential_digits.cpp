#include<bits/stdc++.h>
using namespace std;

vector<int> sequentialdigit(int low ,  int high){
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= 9; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (a > high)
        {
            break;
        }
        if (a <= high && a >= low)
        {
            ans.push_back(a);
        }
        int num = a%10;
        int next = a*10 + (num+1);
        if (num < 9)
        {
            q.push(next);
        }
    }
    return ans;
}

int main(){

}