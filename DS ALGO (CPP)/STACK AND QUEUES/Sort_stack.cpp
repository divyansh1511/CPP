#include<iostream>
using namespace std;
#include<stack>

void insertsortedly(stack<int> &s , int k){
    if (s.empty() || k>=s.top())
    {
        s.push(k);
    }
    
    else
    {
        int b = s.top();
        s.pop();
        insertsortedly(s , k);
        s.push(b);
    }
}

void sortstack(stack<int> &s){
    if (s.size() <= 1)
    {
        return;
    }
    
    int a = s.top();
    s.pop();
    sortstack(s);
    insertsortedly(s,a);
}

int main(){
    stack<int> s;
     s.push(4);
    s.push(3);
    s.push(8);
    s.push(7);

    sortstack(s);
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}