#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,cows;
int positions[N];
bool isvalid(int mid){
    int prev=-1;
    int c=cows;
    for(int i=0;i<n;i++){
        if(positions[i]-prev>=mid || prev==-1){
            prev=positions[i];
            c--;
        }
        if(c==0){
            break;
        }
    }
    return c==0;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    cin>>n>>cows;
	    for(int i=0;i<n;i++){
	        cin>>positions[i];
	    }
	    sort(positions,positions+n);
	    int l=0;
	    int h=1e9;
	    while(h-l>1){
	        int mid=(l+h)/2;
	        if(isvalid(mid)){
	            l=mid;
	        }
	        else{
	            h=mid-1;
	        }
	    }
	    if(isvalid(h)){
	        cout<<h<<endl;
	    }
	    else{
	        cout<<l<<endl;
	    }
	}
	return 0;
}