#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6+10;
long long int n;
long long int m;
long long int trees[N];

bool solve(long long int mid){
    long long int obtained=0;
    for(long long int i=0;i<n;i++){
        if(mid<=trees[i]){
            obtained+=(trees[i]-mid);
        }
    }
    return obtained>=m;
}
int main() {
	cin>>n>>m;
	for(long long int i=0;i<n;i++){
	    cin>>trees[i];
	}
	long long int l=0;
	long long int h=1e9;
	while(h-l>1){
	    long long int mid=(l+h)/2;
	    if(solve(mid)){
	        l=mid;
	    }
	    else{
	        h=mid-1;
	    }
	}
	if(solve(h)){
	    cout<<h<<endl;
	}
	else{
	    cout<<l<<endl;
	}
	return 0;
}

/*Tc: Nlog(H)*/