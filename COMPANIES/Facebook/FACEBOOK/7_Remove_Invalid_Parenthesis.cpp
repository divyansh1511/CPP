#include <bits/stdc++.h>
using namespace std;

void helper(const string &s, int index, int left_remove, int right_remove, int pair, string tmp, unordered_set<string> &st)
{
    if (index == s.length())
    {
        if (left_remove == 0 && right_remove == 0 && pair == 0)
        {
            st.insert(tmp);
        }
        return;
    }

    if (s[index] != '(' && s[index] != ')')
    {
        helper(s, index + 1, left_remove, right_remove, pair, tmp + s[index], st);
    }
    else
    {
        if (s[index] == '(')
        {
            if (left_remove > 0)
            {
                helper(s, index + 1, left_remove - 1, right_remove, pair, tmp, st);
            }
            helper(s, index + 1, left_remove, right_remove, pair + 1, tmp + s[index], st);
        }
        if (s[index] == ')')
        {
            if (right_remove > 0)
            {
                helper(s, index + 1, left_remove, right_remove - 1, pair, tmp, st);
            }
            if (pair > 0)
            {
                helper(s, index + 1, left_remove, right_remove, pair - 1, tmp + s[index], st);
            }
        }
    }
}
vector<string> removeInvalidParentheses(string s)
{
    unordered_set<string> result;
    int left_removed = 0;
    int right_removed = 0;
    for (auto c : s)
    {
        if (c == '(')
        {
            ++left_removed;
        }
        if (c == ')')
        {
            if (left_removed != 0)
            {
                --left_removed;
            }
            else
            {
                ++right_removed;
            }
        }
    }
    helper(s, 0, left_removed, right_removed, 0, "", result);
    return vector<string>(result.begin(), result.end());
}
int main()
{
}