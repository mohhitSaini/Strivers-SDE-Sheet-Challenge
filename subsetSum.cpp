void solve(int index,int k,int sum,vector<int>&arr,vector<int>&bucket,vector<vector<int>>&ans)
{
    if(index>=arr.size())
    {
        if(sum==k)
        ans.push_back(bucket);
        return ;
    }
    //Take
    bucket.push_back(arr[index]);
    solve(index+1,k,sum+arr[index],arr,bucket,ans);
    bucket.pop_back();
    //Not Take
    solve(index+1,k,sum,arr,bucket,ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>bucket;
    // int sum=0;
    solve(0,k,0,arr,bucket,ans);
    return ans;
}