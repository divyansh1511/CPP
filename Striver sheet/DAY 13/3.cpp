#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class stack{
    public:
    queue<int> q;
    void push(int element){
        q.push(element);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        q.front();
    }
    bool empty(){
        return q.empty();
    }
};

int main(){

}