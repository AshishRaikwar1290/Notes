/*https://leetcode.com/problems/partition-equal-subset-sum/*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[210][20005];
    bool subsetsum(int i,int sum,vector<int>& nums){
        if(sum==0) return true;
        if(i<0) return false;
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int ispossible = subsetsum(i-1,sum,nums);
        if(sum-nums[i]>=0){
            ispossible |= subsetsum(i-1,sum-nums[i],nums);
        }
        return dp[i][sum]=ispossible;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;
        return subsetsum(n-1,sum,nums);
    }
};
