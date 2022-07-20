#include<bits/stdc++.h>
using namespace std;

void firstnonrepeating(string s){
    queue<char> q;
    int count[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]-'a']++;
        q.push(s[i]);
        while (!q.empty())
        {
            if (count[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<" ";
                break;
            }
        }
        if (q.empty())
        {
            cout<<-1<<" ";
        }
    }
}

int main(){

}