#include<bits/stdc++.h>
using namespace std;

class queueusingstack{
    public:
    stack<int> s1;
    stack<int> s2;

    void enqueue(int ele){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(ele);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    bool isempty(){
        if (s1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int dequeue(){
        int a = s1.top();
        s1.pop();
        return a;
    }
    int front(){
        return s1.top();
    }
};

int main(){

}