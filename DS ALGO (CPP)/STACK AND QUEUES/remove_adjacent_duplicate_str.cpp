#include<iostream>
using namespace std;
#include<stack>
#include<bits/stdc++.h>

string removeDuplicates(string S) {
        stack<int> t;               //using stack to check duplicate condition 
        string v;                       // to store result
        for(int i=0;i< S.length();i++)             //running loop till end of string 
        {                                                         
            if(t.size()==0)                                //if stack empty push
                t.push(S[i]);
            
            else if(t.top()==S[i])                     // top of stack equal recent array element pop it
                   t.pop();
            else 
                t.push(S[i]);                              // otherwise push it
        }
        
        while(!t.empty()){                        //loop to store stack elements in a string in LIFO order 
            v.push_back(t.top());
            t.pop();
        }
        
     reverse(v.begin(),v.end());                  // reverse the string 
    return v;
}

int main(){
    string s = "abbaca";
    cout<<removeDuplicates(s)<<endl;
}