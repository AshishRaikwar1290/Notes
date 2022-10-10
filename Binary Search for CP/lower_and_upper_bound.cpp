/*lower bound if ele is present then returnh its index otherwise index of just greater element
*/
#include <bits/stdc++.h>
using namespace std;
/*upper bound give index of strictly greater element*/
int upper_bound(vector<int>&v,int element){
    int l=0;
    int h=v.size()-1;
    int mid;
    while(h-l>1){
        mid=(l+h)/2;
        if(v[mid]<=element){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(v[l]>element){
        return l;
    }
    else if(v[h]>element){
        return h;
    }
    else{
        return -1;
    }
}
int lower_bound(vector<int>&v,int element){
    int l=0;
    int h=v.size()-1;
    int mid;
    while(h-l>1){
        mid=(l+h)/2;
        if(v[mid]<element){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(v[l]>=element){
        return l;
    }
    else if(v[h]>=element){
        return h;
    }
    else{
        return -1;
    }
}
int main() {
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i];
	}
	int x;
	cin>>x;
	cout<<lower_bound(v,x);
	return 0;
}