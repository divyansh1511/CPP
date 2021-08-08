#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> modify(queue<int> q , int k){
    stack<int> s;
    queue<int> res;
    while (q.size() != 0)
    {
        int a = q.size();
        if (a < k)
        {
            for (int i = 0; i < a; i++)
            {
                res.push(q.front());
                q.pop();
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
            {
                s.push(q.front());
                q.pop();
            }       
            for (int i = 0; i < k; i++)
            {
                res.push(s.top());
                s.pop();
            }
        }
    }
    return res;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> result = modify(q , 2);
    while (!result.empty())
    {
        int a = result.front();
        result.pop();
        cout<<a<<" ";
    }
    
}