#include <bits/stdc++.h> 
bool solve(int i,int sum,int k,vector<int>&arr,vector<vector<int>>&dp)
{
    if(sum==k)
    return 1;
    if(i==arr.size()||sum>k)
    return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    return dp[i][sum]=solve(i+1,sum,k,arr,dp)|solve(i+1,sum+arr[i],k,arr,dp);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(0,0,k,arr,dp);
}