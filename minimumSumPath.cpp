#include <bits/stdc++.h> 

int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(row>=grid.size()&&col>=grid[0].size())
    return INT_MAX;
    if(row==grid.size()-1&&col==grid[0].size()-1)
    return grid[row][col];
    if(dp[row][col]!=-1) return dp[row][col];

    // int down=1e9,right=1e9;
    // if(row+1<grid.size())
   int down=solve(row+1,col,grid,dp);
    // if(col+1<grid[0].size())
    int right=solve(row,col+1,grid,dp);

    return dp[row][col]=grid[row][col]+min(down,right);
}

int minSumPath(vector<vector<int>> &grid) {
   vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
   return solve(0,0,grid,dp);
}