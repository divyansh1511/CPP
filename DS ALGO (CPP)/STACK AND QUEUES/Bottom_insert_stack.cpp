#include<iostream>
using namespace std;
#include<stack>

void bottominsert(stack<int> &s , int x){
    if (s.size() == 0)
    {
        s.push(x);
    }
    
    else
    {
        int a = s.top();
        s.pop();
        bottominsert(s,x);
        s.push(a);
    }
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    bottominsert(s , 10);
    
    while (!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    
}