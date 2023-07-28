#include <bits/stdc++.h>

int findMaxXOR(int a,int b,vector<int>&arr)
{
	int ans=-1;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]>b) break;
		ans=max(ans,arr[i]^a);
	}
	return ans;
}


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(),arr.end());
	vector<int>ans;
	for(int i=0;i<queries.size();i++)
	{
		int a=queries[i][0];
		int b=queries[i][1];
		ans.push_back(findMaxXOR(a,b,arr));
	}
	return ans;
}