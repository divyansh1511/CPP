#include<iostream>
using namespace std;

int countzeros(int num){
    if (num == 0)
    {
        return 0;
    }
    if (num%10 == 0)
    {
        return 1+countzeros(num/10);
    }
    return countzeros(num/10);
}

int main(){
    int num;
    cout<<"Enter any number"<<endl;
    cin>>num;
    cout<<endl<<"Number of zeros in "<<num<<" are "<<countzeros(num);
}