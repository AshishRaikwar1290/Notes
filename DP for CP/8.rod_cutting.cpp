//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1005];
    int solve(int len,vector<int>&prices){
        if(len==0) return 0;
        if(dp[len]!=-1){
            return dp[len];
        }
        int ans=0;
        for(int len_to_cut=1;len_to_cut<=prices.size();len_to_cut++){
            if(len-len_to_cut>=0){
            ans=max(ans,solve(len-len_to_cut,prices)+prices[len_to_cut-1]);
            }
        }
        return dp[len]=ans;
    }
    int cutRod(int price[], int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>prices(price,price+n);
        return solve(n,prices);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends