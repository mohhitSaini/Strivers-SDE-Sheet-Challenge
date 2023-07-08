bool isPossible(int row,int col,vector<vector<int>>&temp)
{
    int n=temp.size();
    for(int i=0;i<col;i++)
    {
        if(temp[row][i]==1)
        return false;
    }
    for(int i=0;i<row;i++)
    {
        if(temp[i][col]==1)
        return false;
    }
    for(int i=1;i<=col;i++)
    {
        if(row-i>=0&&col-i>=0)
        {
            if(temp[row-i][col-i]==1)
            return false;
        }
        if(row+i<n&&col-i>=0)
        {
            if(temp[row+i][col-i]==1)
            return false;
        }
    }
    return true;
}

void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&temp,int n)
{
    //Base case
    if(col>=n)
    {
        vector<int>ans1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            ans1.push_back(temp[i][j]);
        }
        ans.push_back(ans1);
        return ;
    }

    for(int row=0;row<n;row++)
    {
        if(isPossible(row,col,temp)==true)
        {
            temp[row][col]=1;
            solve(col+1,ans,temp,n);
            temp[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
   vector<vector<int>>temp(n,vector<int>(n,0));
   vector<vector<int>>ans;
   solve(0,ans,temp,n);
   return ans;
}