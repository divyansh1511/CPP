// {[]()} ---> true      {[)}--->false

#include<iostream>
using namespace std;
#include<stack>

bool isbalanced(string str){
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char currchar = str[i];
        if (currchar == '{' || currchar == '[' || currchar == '(')
        {
            s.push(currchar);
        }
        else if (currchar == '}')
        {
            if (s.empty())
            {
                return false;
            }
            
            char last =  s.top();
            s.pop();
            if (last != '{')
            {
                return false;
            }
            
        }
        else if (currchar == ']')
        {
            if (s.empty())
            {
                return false;
            }
            
            char last = s.top();
            s.pop();
            if (last != '[')
            {
                return false;
            }
        }
        else if (currchar == ')')
        {
            if (s.empty())
            {
                return false;
            }
            
            char last = s.top();
            s.pop();
            if (last != '(')
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    string str;
    cin>>str;
    cout<<isbalanced(str)<<endl;
}