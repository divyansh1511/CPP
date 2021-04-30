// Given k find the geometric Sum  i.e.  1 + 1/2 + 1/4 + 1/8 + … + 1/(2^k)
#include<iostream>
#include<math.h>
using namespace std;

double geometricSum(int k){
    if (k == 0){
        return 1;
    }
    return  pow(0.5,k) + geometricSum(k-1);
}
int main(){
    int k;
    cout<<"Enter any number"<<endl;
    cin>>k;
    cout<<geometricSum(k)<<endl;
}