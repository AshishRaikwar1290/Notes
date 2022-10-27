#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int wt[N];
int val[N];
long long int dp[105][100009];
long long int solve(int idx,int wt_left){
    if(wt_left==0) return 0;
    if(idx < 0) return 0;
    if(dp[idx][wt_left]!=-1) return dp[idx][wt_left];
    long long int ans = solve(idx-1,wt_left);
    if(wt_left-wt[idx]>=0){
        ans=max(ans,solve(idx-1,wt_left-wt[idx])+val[idx]);
    }
    return dp[idx][wt_left]=ans;
}
int main() {
	int n,w;
	cin>>n>>w;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
	    cin>>wt[i]>>val[i];
	}
	cout<<solve(n-1,w);
	return 0;
}