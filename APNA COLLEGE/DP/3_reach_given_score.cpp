#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;
	for(int i=3;i<=n;i++){
	    table[i] += table[i-3];
	}
	for(int i=5;i<=n;i++){
	    table[i] += table[i-5];
	}
	for(int i=10;i<=n;i++){
	    table[i] += table[i-10];
	}
	return table[n];
}

int main(){

}