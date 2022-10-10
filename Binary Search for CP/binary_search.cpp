/*monotonic function which maintains a given order
predicate function
FFFFFTTTTT
or 
TTTTTFFFFF
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	int x;
	cin>>x;
	int l=0;
	int h=n-1;
	int mid;
	while(h-l>1){
	    mid=(l+h)/2;
	    if(v[mid]<x){
	        l=mid+1;
	    }
	    else{
	        h=mid;
	    }
	}
	if(v[l]==x){
	    cout<<l<<endl;
	}
	else if(v[h]==x){
	    cout<<h<<endl;
	}
	else{
	    cout<<"Not found";
	}
	return 0;
}
/*TC: o(logn base 2)*/