#include <bits/stdc++.h> 

bool isPossible(int row,int col,vector<vector<int>>&maze,vector<vector<int>>&visited)
{
  if(row>=0&&col>=0&&row<maze.size()&&col<maze.size()&&!visited[row][col]&&maze[row][col])
  return true;
  return false;
}

void solve(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&maze,vector<vector<int>>&ans)
{
  if(row==0&&col==0)
  {
    vector<int>temp;
    for(int i=0;i<maze.size();i++)
    {
      for(int j=0;j<maze.size();j++)
      {
        temp.push_back(visited[i][j]);
      }
    }
    ans.push_back(temp);
    return ;
  }


    int dr[]={0,1,0,-1};
    int dc[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {
      int nrow=row+dr[i];
      int ncol=col+dc[i];
      if(isPossible(nrow,ncol,maze,visited))
      {
        visited[nrow][ncol]=1;
        solve(nrow,ncol,visited,maze,ans);
        visited[nrow][ncol]=0;
      }
    }
    
  
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>visited(n,vector<int>(n,0));
  if(maze[n-1][n-1]==0) return {{}};
  visited[n-1][n-1]=1;
  vector<vector<int>>ans;
  solve(n-1,n-1,visited,maze,ans);
  return ans;
}