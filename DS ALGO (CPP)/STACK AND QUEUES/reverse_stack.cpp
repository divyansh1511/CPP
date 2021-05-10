#include<iostream>
using namespace std;
#include<stack>

void bottominsert(stack<int> &s , int a){
    if (s.size() == 0)
    {
        s.push(a);
    }
    
    else
    {
        int b = s.top();
        s.pop();
        bottominsert(s,a);
        s.push(b);
    }
}

void reversestack(stack<int> &s){
    if (s.size() <= 1)
    {
        return;
    }
    
    int a = s.top();
    s.pop();
    reversestack(s);
    bottominsert(s , a);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reversestack(s);
    
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}