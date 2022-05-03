#include<bits/stdc++.h>
using namespace std;

int maxarea(vector<int> heights){
    int ans = 0;
    int i = 0 , j = heights.size() - 1;
    while (i < j)
    {
        ans = max(ans , (j-i)*min(heights[i] , heights[j]));
        heights[i] > heights[j] ? j-- : i++;
    }
    return ans;
}

int main(){

}