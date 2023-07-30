int solve(int index,int target,vector<int>&price,vector<vector<int>>&dp)
{
	if(index==0)
	{
		return target*price[0];
	}
	if(dp[index][target]!=-1) return dp[index][target];
	int notTake=0+solve(index-1,target,price,dp);
	int take=INT_MIN;
	if(target>=index+1)
	take=price[index]+solve(index,target-index-1,price,dp);

	return dp[index][target]=max(take,notTake);
}

int cutRod(vector<int> &price, int n)
{
	// vector<vector<int>>dp(n,vector<int>(n+1,0));
	// return solve(n-1,n,price,dp);
	vector<int>prev(n+1,0);
	vector<int>cur(n+1,0);
	for(int i=0;i<=n;i++)
	{
		prev[i]=i*price[0];
	}

	for(int index=1;index<n;index++)
	{
		for(int target=0;target<=n;target++)
		{
			int notTake=0+prev[target];
			int take=INT_MIN;
			if(target>=index+1)
			take=price[index]+cur[target-index-1];
			cur[target]=max(take,notTake);
		}
		prev=cur;
	}
	return prev[n];
}
