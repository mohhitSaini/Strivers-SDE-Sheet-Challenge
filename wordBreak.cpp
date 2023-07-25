#include <bits/stdc++.h> 

bool isPossible(string str,vector<string>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==str)
        return true;
    }
    return false;
}

bool solve(int index,string str,vector<string>&arr,int n,vector<int>&dp)
{
    if(index>=n)
    return true;
    if(dp[index]!=-1) return dp[index];

    for(int i=0;i<str.length();i++)
    {
        if(isPossible(str.substr(0,i+1),arr))
        {
            if(solve(index+i+1,str.substr(i+1),arr,n,dp)==true) return dp[index]=true;
        }
    }
    return dp[index]=false;
}


bool wordBreak(vector < string > & arr, int n, string & target) {
    vector<int>dp(target.length(),-1);
    return solve(0,target,arr,target.length(),dp);
}