#include<iostream>
using namespace std;

class stackusingarr{
    int* data;
    int lastelementindex;
    int capacity;

    public:
    stackusingarr(){
        data = new int[20];
        lastelementindex = -1;
        capacity = 20;
    }
    int size(){
        return lastelementindex+1;
    }
    bool isempty(){
        return lastelementindex == -1;
    }
    void push(int element){
        if (lastelementindex == capacity)
        {
            int* newdata = new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            capacity = capacity*2;
            delete[] data;
            data = newdata;
        }
        lastelementindex++;
        data[lastelementindex] = element;
    }

    int pop(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[lastelementindex--];
    }

    int top(){
        if (isempty())
        {
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return data[lastelementindex];
    }
};

int main(){
    stackusingarr s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
}