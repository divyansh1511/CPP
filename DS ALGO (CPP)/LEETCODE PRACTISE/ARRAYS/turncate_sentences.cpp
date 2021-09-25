#include<iostream>
using namespace std;

string truncateSentence(string s, int k) {
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            c++;
        }
        if (c == k)
        {
            s.erase(s.begin()+i , s.end());
            break;
        }
    }
    return s;
}

int main(){
    cout<<truncateSentence("hello bro how are you" , 4)<<endl;
}