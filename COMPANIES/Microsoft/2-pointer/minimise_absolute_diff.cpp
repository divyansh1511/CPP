#include<bits/stdc++.h>
using namespace std;

int minabsolutediff(vector<int> v1 , vector<int> v2 , vector<int> v3){
    int n = v1.size() , m = v2.size() , l = v3.size();
    int i = 0 , j = 0 , k = 0;
    int ans = INT_MAX;
    while (i < n && j < m && k < l)
    {
        int minval = min({v1[i] , v2[j] , v3[k]});
        int maxval = max({v1[i] , v2[j] , v3[k]});

        ans = min(ans , abs(maxval - minval));
        if (min(min(v1[i+1],v2[j+1]),v3[k+1]) == v1[i+1])
        {
            i++;
        }
        else if (min(min(v1[i+1],v2[j+1]),v3[k+1]) == v2[j+1])
        {
            j++;
        }
        else if (min(min(v1[i+1],v2[j+1]),v3[k+1]) == v3[k+1])
        {
            k++;
        }
    }
    return ans;
}

int main(){

}