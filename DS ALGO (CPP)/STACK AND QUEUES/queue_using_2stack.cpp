#include<iostream>
#include<stack>
using namespace std;

class queueusingstack{
    stack<int> s1;
    stack<int> s2;

    public:
    void enqueue(int element){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(element);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue(){
        if (s1.empty()) {
            cout << "Q is Empty";
            return 0;
        }
 
        int x = s1.top();
        s1.pop();
        return x;
    }

    int front(){
        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }
        return s1.top();
    }
};

int main(){
    queueusingstack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
 
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
}