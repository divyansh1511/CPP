#include<iostream>
#include<stack>
using namespace std;

bool reductantbracket(string str){
    stack<int> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            s.push(str[i]);
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                return true;
            }
            
            while (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    string str;
    cin>>str;
    cout<<reductantbracket(str)<<endl;
}