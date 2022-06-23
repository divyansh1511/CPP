#include<bits/stdc++.h>
using namespace std;

string reversestring(string s){
    reverse(s.begin() , s.end());
    return s;
}

bool checkPalindrome(string s){
    int i = 0 , j = s.length() -1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

vector<pair<char,int>> findDuplicate(string s){
    unordered_map<char , int> mp;
    vector<pair<char , int>> v;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for(auto it : mp){
        if (it.second > 1)
        {
            v.push_back({it.first , it.second});
        }
    }
    return v;
}

bool isrotationofother(string a , string b){
    if (a.length() != b.length())
    {
        return false;
    }
    string c = a+a;
    return c.find(b) != string::npos;
}

string count_and_say(int n){
    if (n == 1)
    {
        return "1";
    }
    if (n == 2)
    {
        return "11";
    }
    string s = "11";
    for (int i = 3; i <= n; i++)
    {
        string t = "";
        s += "&";
        int c = 1;
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != s[j-1])
            {
                t += to_string(c);
                t += s[j-1];
                c = 1;
            }
            else
            {
                c++;
            }
        }
        s = t;
    }
    return s;
}

string longestPalindromeSubstring(string s){
    int n = s.length();
    if (n < 2)
    {
        return s;
    }
    int mxlen = 1 , st = 0;
    int low , high;
    for (int i = 0; i < n; i++)
    {
        low = i-1;
        high = i+1;
        while (high < n && s[high] == s[i])
        {
            high++;
        }
        while (low >= 0 && s[low] == s[i])
        {
            low--;
        }
        while (low >= 0 && high < n && s[low] == s[high])
        {
            low--;
            high++;
        }
        int len = high-low-1;
        if (mxlen < len)
        {
            mxlen = len;
            st = low+1;
        }
    }
    return s.substr(st , mxlen);
}

void helper(string s , int n , int ind , string curr , vector<string> &v){
    if (ind == n)
    {
        return;
    }
    if (!curr.empty())
    {
        v.push_back(curr);
    }
    for (int i = ind+1; i < n; i++)
    {
        curr += s[i];
        helper(s , n , i , curr , v);
        curr.erase(curr.size()-1);
    }
}

vector<string> printsubseq(string s){
    vector<string> v;
    helper(s , s.size() , -1 , "" , v);
    return v;
}

void help(string s , int l , int r, vector<string> &v){
    if (l == r)
    {
        v.push_back(s);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[l] , s[i]);
        help(s , l+1 , r , v);
        swap(s[l] , s[i]);
    }
}

vector<string> allpermutations(string s){
    vector<string> v;
    help(s , 0 , s.length()-1 , v);
    return v;
}

int editdistance(string s , string t){
    int m = s.length() , n = t.length();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] =  i;
            }
            else if (s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1+min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]});
            }
        }
    }
    return dp[m][n];
}

bool wordBreak(string s , vector<string> v){
    vector<bool> dp(s.length()+1 , false);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && find(v.begin() , v.end() , s.substr(j , i-j)) != v.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

string printSequence(string S)
{
    string arr[] = {"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    string output = "";

    int n = S.length();
    for (int i=0; i<n; i++)
    {
        if (S[i] == ' ')
            output = output + "0";
 
        else
        {
            int position = S[i]-'A';
            output = output + arr[position];
        }
    }
    return output;
}

int countreversals(string s){
    int c=0; 
    stack <char> st;
    for(int i=0 ;i<s.size(); i++){
        if(s[i] == '{') {
            if(st.empty())
            st.push(s[i]);
            else if(st.top() == '{'){
               st.push(s[i]);
            }
        }
        if(s[i] == '}'){
            if(st.empty()){
                c++;
                st.push('{');
            }
            else if(st.top() == '{'){
                st.pop();
            }
            else if(st.top() == '}'){
                c++;
                st.pop();
            }
        }
    }
    if(st.empty()) return c;
    if(st.size()%2==0){
        return (st.size()/2)+c;
    }
    return -1;
}

string LongestCommonPrefix(vector<string> &v){
    int n = v.size();
    string ans = "";
    if (n == 0)
    {
        return "";
    }
    sort(v.begin() , v.end());
    string a = v[0];
    string b = v[n-1];
    string ans = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
        ans += a[i];
    }
    return ans;
}

int minswapstomakealternate(string s){
    int count1 = 0 , count2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((i%2 == 0 && s[i] != '0') || (i%2 != 0 && s[i] != '1'))
        {
            count1++;
        }
        if ((i%2 == 0 && s[i] != '1') || (i%2 == 0 && s[i] != '0'))
        {
            count2++;
        }
    }
    return min(count1 , count2);
}

bool isomorphicstring(string str1 , string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    int count[26] = {0};
    int dcount[26] = {0};
    for(int i=0;i<str1.length();i++){
        count[str1[i] - 'a']++;
        dcount[str2[i] - 'a']++;
        if(count[str1[i] - 'a'] != dcount[str2[i] - 'a']){
            return false;
        }
    }
    return true;
}

int vowelandcons(string a){
    int n = a.length();
    if (n == 1)
    {
        return 0;
    }
    int cons = 0 , vowel = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            vowel++;
        }
        else
        {
            cons++;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
        {
            count += cons;
            vowel--;
        }
        else
        {
            count += vowel;
            cons--;
        }
    }
    return count;
}

int romanToInt(string A) {
    unordered_map<char , int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int n = A.length();
    int sum = mp[A[n-1]];
    for(int i=n-2;i>=0;i--){
        if(mp[A[i]] < mp[A[i+1]]){
            sum -= mp[A[i]];
        }
        else{
            sum += mp[A[i]];
        }
    }
    return sum;
}

string MulitplyStrings(string a , string b){
    int n = a.length();
    int m = b.length();
    string res(n+m , '0');
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int num = (a[i]-'0')*(b[j]-'0') + res[i+j+1] - '0';
            res[i+j+1] = num%10 + '0';
            res[i+j] += num/10;
        }
    }
    for (int i = 0; i < res.length(); i++)
    {
        if (res[i] != '0')
        {
            return res.substr(i);
        }
    }
    return "0";
}

string addbinary(string a , string b){
    int i = a.length() - 1 , j = b.length() - 1;
    string res = "";
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i] - '0';
        }
        if (j >= 0)
        {
            sum += b[j] - '0';
        }
        carry = (sum > 1) ? 1 : 0;
        res += to_string(sum%2);
    }
    if (carry)
    {
        res += '1';
    }
    reverse(res.begin() , res.end());
    return res;
}

int myAtoi(string s){
    long long int res = 0;
    int indi = 1;
    int n = s.size();
    if(n==0){
        return 0;
    }
    int i=0;
    while((s[i] == ' ') && (i<n)){
        i++;
    }
    if(i == n){
        return 0;
    }
    if((s[i] == '-' || s[i] == '+') && i<n){
        indi = (s[i++] == '-') ? -1 : 1;
    }
    while(s[i] >= '0' && s[i] <= '9' && i<n){
        res = res*10 + (s[i++] - '0');
        if(res*indi >= INT_MAX){
            return INT_MAX;
        }
        if(res*indi <= INT_MIN){
            return INT_MIN;
        }
    }
    return res*indi;
}

//-------Exaclty One Swap --- gfg 

long long countStrings(string S)
{
    map<char,long long>mp;
    long long ans=1,n=S.length();
    bool check=false;
    for(long long i=0;i<n;i++){
        mp[S[i]]++;
        if(mp[S[i]]>1)
            check=true;
    }
    for(long long i=0;i<n;i++){
        ans+=n-i-1-(mp[S[i]]-1);
        mp[S[i]]--;
    }
    if(check==false)
        return ans-1;
    else return ans;
}

int main(){

}