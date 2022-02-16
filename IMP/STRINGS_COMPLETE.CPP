#include<bits/stdc++.h>
using namespace std;

int length_of_last_word(string s){
    int n = s.length();
    int i = n-1;
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    int count = 0;
    while (i>=0 && s[i] != ' ')
    {
        count++;
        i--;
    }
    return count;
}

string reverse_by_words(string s){
    stack<string> st;
    int n = s.length();
    int count = 0;
    string a = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (count != 0)
            {
                st.push(a);
            }
            count = 0;
            a = "";
        }
        else
        {
            count++;
            a += s[i];
        }
    }
    if (a != "")
    {
        st.push(a);
    }
    string ans = st.top();
    st.pop();
    while (!st.empty())
    {
        ans += " ";
        ans += st.top();
        st.pop();
    }
    return ans;
}

bool palindromeString(string s){
    transform(s.begin() , s.end() , s.begin() , ::tolower);
    int n = s.length();
    string a = "";
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        {
            a += s[i];
        }
    }
    int i=0 , j = a.length();
    while (i<=j)
    {
        if(a[i] != a[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestCommonprefix(vector<string> v){
    string a = v[0];
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < a.length(); j++)
        {
            if (a[j] != v[i][j])
            {
                a.erase(j);
                break;
            }
        }
    }
    return a;
}

int atoi(string s){
    long long int res = 0;
    int indi = 1;
    int n = s.length();
    if (n == 0)
    {
        return 0;
    }
    int i = 0;
    while (s[i] == ' ' && i<n)
    {
        i++;
    }
    if(s[i] == '+' || s[i] == '-'){
        indi = s[i] == '+' ? 1 : -1;
    }
    while (s[i] >= '0' && s[i] <= '9' && i<n)
    {
        res = res*10 + s[i]-'0';
        if (res*indi >= INT_MAX)
        {
            return INT_MAX;
        }
        if(res*indi <= INT_MIN)
        {
            return INT_MIN;
        }
    }
    return res*indi;
}

int noofsubstringvowelandcons(string a){
    int count = 0;
    int vow = 0 , cons = 0;
    int n = a.length();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            vow++;
        }
        else
        {
            cons++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            count += cons;
            vow--;
        }
        else
        {
            count += vow;
            cons--;
        }
    }
    return count;
}

string removeconsecutive(string s , int k){
    int count = 1;
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i+1])
        {
            count++;
        }
        else
        {
            if(count == k){
                count = 1;
                continue;
            }
            ans += s[i];
            count = 1;
        }
    }
    return ans;
}

string addBinary(string a , string b){
    int i = a.length() - 1 , j = b.length() - 1;
    string ans = "";
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += b[j--] - '0';
        }
        carry = (sum > 1) ? 1 : 0;
        ans += to_string(sum%2);
    }
    if (carry)
    {
        ans += '1';
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

string inttoroman(int A){
    string str[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
    int val[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
    
    string s = "";
    for(int i=0; A!=0 ; i++){
        while(A >= val[i]){
            A -= val[i];
            s += str[i];
        }
    }
    return s;
}

int main(){
    // string s = "race a car";
    // cout<<length_of_last_word(s)<<endl;
    // cout<<reverse_by_words(s)<<endl;
    // cout<<palindromeString(s)<<endl;
}