#include<bits/stdc++.h>
using namespace std;

void twosum1(vector<int> arr , int target){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[i]+arr[j] == target)
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}

//--------------------------Can't do this as it changes the index of ------------------------------

// void twosum2(vector<int> arr , int target){
//     sort(arr.begin() , arr.end());
//     int i=0 , j = arr.size() - 1;
//     while (i<j)
//     {
//         if(arr[i] + arr[j] < target){
//             i++;
//         }
//         else if (arr[i] + arr[j] > target)
//         {
//             j--;
//         }
//         else
//         {
//             cout<<i<<" "<<j<<endl;
//             break;
//         }
//     }
// }

void twosum3(vector<int> arr , int target){
    unordered_map<int , int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        int tt = target - arr[i];
        if (mp.find(tt) != mp.end())
        {
            cout<<i<<" "<<mp[tt]<<endl;
            break;
        }
        mp[arr[i]] = i;
    }
}

int main(){
    vector<int> arr = {3,2,3};
    twosum1(arr , 6);
    // twosum2(arr , 6);
    twosum3(arr , 6);
}