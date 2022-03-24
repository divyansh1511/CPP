#include<bits/stdc++.h>
using namespace std;

// vector<int> anagrams(string str , string p){
//     vector<int> v;
//     sort(p.begin() , p.end());
//     int n = p.length();
//     int k = str.length();
//     string a;
//     for (int i = 0; i < k - n+1; i++)
//     {
//         // cout<<n<<endl;
//         a = str.substr(i , i+n);
//         cout<<a<<endl;
//         sort(a.begin() , a.end());
//         // cout<<a<<endl;
//         if (a == p)
//         {
//             // cout<<i<<endl;
//             v.push_back(i);
//         }
//         a.clear();
//     }
//     return v;
// }

vector<int> anagrams(string a , string b){
    vector<int> pv(26,0) , sv(26 , 0) , res;
    if (a.size() < b.size())
    {
        return res;
    }
    if (pv == sv)
    {
        res.push_back(0);
    }
    for (int i = b.size(); i < a.size(); i++)
    {
        ++sv[a[i] - 'a'];
        --sv[a[i-b.size()] - 'a'];
        if (pv == sv)
        {
            res.push_back(i-b.size()+1);
        }
    }
    return res;
}

int main(){
    vector<int> v = anagrams("cbaebabacd" , "abc");
    string a = "cbaebabacd";
    // cout<<a.substr(1,3)<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    
}