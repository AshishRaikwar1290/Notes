#include<bits/stdc++.h>
using namespace std;
const int N = 25e2+10;
vector<int>a(N);
int dp[N];
int lis(int i){
    if(dp[i]!=-1) return dp[i];
    int ans=1;
    for(int j=0;j<i;j++){
        if(a[j]<a[i]){
            ans=max(ans,lis(j)+1);
        }
    }
    return dp[i] = ans;
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int i=0;i<n;i++){
	    ans=max(ans,lis(i));
	}
	cout<<ans<<endl;
	return 0;
}
 

/* 
8
10 9 2 5 3 7 101 18

4

TC: O(n^2)
SC: O(n)
*/