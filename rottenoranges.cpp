#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            q.push({0,{i,j}});
        }
    }
    int flevel=0;
    while(!q.empty())
    {
        int level=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        flevel=max(flevel,level);
        q.pop();
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int i=0;i<4;i++)
        {
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&grid[nrow][ncol]!=2&&grid[nrow][ncol]==1)
            {
                grid[nrow][ncol]=2;
                q.push({level+1,{nrow,ncol}});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!=0&&grid[i][j]==1)
            return -1;
        }
    }
    return flevel;
}