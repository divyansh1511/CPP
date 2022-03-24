#include<bits/stdc++.h>
using namespace std;

int max_subarr_sum(int arr[] , int n){
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxsum = max(maxsum , sum);
    }
    return maxsum;
}

int find_duplicate(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        if (arr[a] == -1)
        {
            return a;
        }
        arr[a] = -1;
    }
    return -1;
}

void spiralmatrix(vector<vector<int>> arr){
    int i=0,j=0 , n = arr.size() , m = arr[0].size() , k;
    while (i < n && j < m)
    {
        for (k = 0; k < m; k++)
        {
            cout<<arr[i][k]<<" ";
        }
        i++;
        for (k = i; k < n; k++)
        {
            cout<<arr[k][m-1]<<" ";
        }
        m--;
        if (i < n)
        {
            for (k = m-1; k >= 0; k--)
            {
                cout<<arr[n-1][k]<<" ";
            }
            n--;
        }
        if (j < m)
        {
            for (k = n-1; k >= 0 ; k--)
            {
                cout<<arr[k][i]<<" ";
            }
            j++;
        }
    }
}

static bool cmp(int a , int b){
    string a1 = to_string(a);
    string b1 = to_string(b);
    return a1+b1 > b1+a1;
}

string largest_number(int arr[] , int n){
    sort(arr , arr+n , cmp);
    string ans = "";
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
        if (arr[i] == 0)
        {
            c++;
        }
    }
    if (c == n)
    {
        return "0";
    }
    return ans;
}

int findmissingno(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int a = arr[i] - 1;
        if (arr[a] != arr[i])
        {
            swap(arr[a] , arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i+1)
        {
            return i+1;
        }
    }
    return n;
}

vector<int> addone(vector<int> v){
    reverse(v.begin() , v.end());
    vector<int> ans;
    int carry = 1;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i]+carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    while (carry)
    {
        ans.push_back(carry%10);
        carry /= 10;
    }
    while (ans[ans.size() - 1] == 0 && ans.size() > 1)
    {
        ans.pop_back();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

int maxdis(int arr[] , int n){
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end());
    int ans=0;
    int rmax=v[n-1].second;
    for(int i=n-2;i>=0;i--){
        ans=max(ans,rmax-v[i].second);
        rmax=max(rmax,v[i].second);
    }
    return ans;
}

vector<int> nextpermuation(vector<int> v){
    int n = v.size();
    int k , l;
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for (l = n-1; l > k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
    return v;
}

vector<vector<int>> antidiagonals(vector<vector<int>> v){
    int n = v.size();
    int b = 2*(n-1) + 1;
    vector<vector<int>> ans(b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i+j].push_back(v[i][j]);
        }
    }
    return ans;
}

//----------------------------MATHS----------------------------------

int path(int a , int b){
    vector<vector<int>> v(a , vector<int>(b,1));
    for (int i = 1; i < a; i++)
    {
        for (int j = 1; j < b; j++)
        {
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }
    return v[a-1][b-1];
}

int trailingzeros(int n){
    int res = 0;
    for (long long i = 5; (n/i) > 0; i *= 5)
    {
        res += (n/i);
    }
    return res;
}

int main(){

}