#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MaximumPopulation(vector<vector<int>> logs){
    vector<int> v(2051,0);
        for(auto a:logs){
            v[a[0]]+=1;
            v[a[1]]-=1;
        }
        for(int i=1;i<2051;i++){
            v[i]+=v[i-1];
        }
        
        int a = INT_MIN;
        int ans = 0;
        for(int i=0;i<2051;i++){
            if(a<v[i]){
                a=v[i];
                ans=i;
            }
        }
    return ans;
}

int main(){
    vector<vector<int>> d;
    //std::vector<int> d;
    int in,i,j,temp;
    cout<<"Enter the N number of ship and port:"<<endl;
    cin>>in;
    cout<<"Enter preference etc..:\n";
    for(i=0; i<in; i++){ 
        cout<<"ship"<<i+1<<":"<<' ';
        for(j=0; j<in; j++){
            cin>>temp;
            d[i].push_back(temp);// I don't know how to push_back here!!
        }
    }
}