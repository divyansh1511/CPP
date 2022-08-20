#include<bits/stdc++.h>
using namespace std;

string decodestring(string s){
    stack<int> stnum;
    stack<string> ststr;
    string res = "";
    int num = 0;
    for(char it : s){
        if(isdigit(it)){
            num = num*10 + it - '0';
        }
        else if(isalpha(it)){
            res += it;
        }
        else if(it == '['){
            ststr.push(res);
            stnum.push(num);
            res = "";
            num = 0;
        }
        else if(it == ']'){
            string temp = res;
            for(int i=1;i<stnum.top();i++){
                res += temp;
            }
            res = ststr.top() + res;
            ststr.pop();
            stnum.pop();
        }
    }
    return res;
}

int main(){

}