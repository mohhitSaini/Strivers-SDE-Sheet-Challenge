#include <bits/stdc++.h>
void solve(int index,int sum,int k,vector<int>&bucket,vector<int>&arr,vector<vector<int>>&ans)
{
    if(index==arr.size())
    {
        if(sum==k)
        ans.push_back(bucket);
        return;
    }

    bucket.push_back(arr[index]);
    solve(index+1,sum+arr[index],k,bucket,arr,ans);
    bucket.pop_back();
    solve(index+1,sum,k,bucket,arr,ans);

}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int>bucket;
    vector<vector<int>>ans;
    solve(0,0,k,bucket,arr,ans);
    return ans;
}