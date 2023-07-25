#include <bits/stdc++.h> 

void dfs(int node,stack<int>&st,vector<int>&vis,vector<int>adjLis[])
{
    vis[node]=1;
    for(auto it:adjLis[node])
    {
        if(!vis[it])
        {
            dfs(it,st,vis,adjLis);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
   stack<int>st;
   vector<int>vis(v,0);
   vector<int>adjLis[v];
   for(int i=0;i<edges.size();i++)
   {
       adjLis[edges[i][0]].push_back(edges[i][1]);
   }
   for(int i=0;i<v;i++)
   {
       if(!vis[i])
       dfs(i,st,vis,adjLis);
   }
   vector<int>ans;
   while(!st.empty())
   {
       ans.push_back(st.top());
       st.pop();
   }
   return ans;
}