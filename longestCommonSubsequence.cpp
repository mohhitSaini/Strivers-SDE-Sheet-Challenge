#include <bits/stdc++.h>
int lcs(string s, string t)
{
	vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,0));
	for(int i=1;i<=s.length();i++)
	{
		for(int j=1;j<=t.length();j++)
		{
			if(s[i-1]==t[j-1])
			dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[s.length()][t.length()];
}