int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            dp[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        dp[u][v]=wt;
    }

    for(int via=1;via<=n;via++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dp[i][via]+dp[via][j]<dp[i][j]&&dp[i][via]!=1e9&&dp[via][j]!=1e9)
                dp[i][j]=dp[i][via]+dp[via][j];
            }
        }
    }
    return dp[src][dest];
}