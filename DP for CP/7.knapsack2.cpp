#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int wt[N];
int val[N];
long long int dp[105][100009];
// for a particular value min weight
long long int solve(int idx,int value_left){
    if(value_left==0) return 0;
    if(idx < 0) return 1e15;
    if(dp[idx][value_left]!=-1) return dp[idx][value_left];
    long long int ans = solve(idx-1,value_left);
    if(value_left-val[idx]>=0){
        ans=min(ans,solve(idx-1,value_left-val[idx])+wt[idx]);
    }
    return dp[idx][value_left]=ans;
}
int main() {
	int n,w;
	cin>>n>>w;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
	    cin>>wt[i]>>val[i];
	}
	long long int max_value=1e5;
	for(long long int i=max_value;i>=1;i--){
	    if(solve(n-1,i)<=w){
	        cout<<i<<endl;
	        break;
	    }
	}
	return 0;
}