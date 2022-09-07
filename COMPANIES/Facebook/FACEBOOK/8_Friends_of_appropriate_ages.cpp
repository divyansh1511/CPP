#include <bits/stdc++.h>
using namespace std;

//-----------brute force---------------------//

int friendsofages(vector<int> &ages)
{
    int n = ages.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!(ages[j] <= 0.5 * ages[i] + 7) && !(ages[j] > ages[i]) && !(ages[j] > 100 && ages[i] < 100))
            {
                c++;
            }
            if (!(ages[i] <= 0.5 * ages[j] + 7) && !(ages[i] > ages[j]) && !(ages[i] > 100 && ages[j] < 100))
            {
                c++;
            }
        }
    }
    return c;
}

//-----------------optimal-----------------//

bool helper(int a , int b){
    return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
}

int friendsofages(vector<int> &ages){
    unordered_map<int,int> mp;
    for (int i = 0; i < ages.size(); i++)
    {
        mp[ages[i]]++;
    }
    int c = 0;
    for(auto it1 : mp){
        for(auto it2 : mp){
            if(helper(it1.first , it2.first)){
                c += it1.second * (it2.second - (it1.first == it2.first ? 1 : 0));
            }
        }
    }
    return c;
}

int main()
{

}