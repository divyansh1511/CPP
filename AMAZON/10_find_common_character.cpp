#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &words)
{
    vector<string> ans;
    for (auto it : words[0])
    {
        bool ispresent = true;
        string s = "";
        for (int i = 1; i < words.size(); i++)
        {
            int index = words[i].find(it);
            if (index != -1)
            {
                words[i].erase(index, 1);
            }
            else
            {
                ispresent = false;
                break;
            }
        }
        if (ispresent)
        {
            ans.push_back(s += it);
        }
    }
    return ans;
}

int main()
{
    
}