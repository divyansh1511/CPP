#include<bits/stdc++.h>
using namespace std;

class stackusingqueue{
    public:
    queue<int> q;

    void push(int x){
        q.push(x);
        for (int i = 0; i < q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop(int x){
        int a = q.front();
        q.pop();
        return a;
    }
    int top(){
        return q.front();
    }
};

int main(){

}