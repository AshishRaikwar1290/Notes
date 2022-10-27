#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10001];
    int solve(int amount,vector<int>& coins){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans=INT_MAX-1;
        for(auto coin: coins){
            if(amount-coin>=0){
             ans=min(ans,1+solve(amount-coin,coins));
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp,-1,sizeof(dp));
        int res = solve(amount,coins);
        return (res==INT_MAX-1)?-1:res;
    }
};