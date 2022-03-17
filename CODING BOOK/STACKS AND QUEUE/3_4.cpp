#include<bits/stdc++.h>
using namespace std;

class queueusingstack{
    stack<int> s1;
    stack<int> s2;

    public:
    void inqueue(int a){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(a);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int dequeue(){
        if (s1.empty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        else
        {
            int a = s1.top();
            s1.pop();
            return a;
        }
    }
    int front(){
        if (s1.empty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return s1.top();
    }
};

int main(){
    queueusingstack q;
    q.inqueue(1);
    q.inqueue(2);
    q.inqueue(3);
 
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
}