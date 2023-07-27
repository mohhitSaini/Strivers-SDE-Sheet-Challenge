#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,
 vector<pair<pair<int, int>, int>> &g)
{

    vector<pair<int,int>>adjLis[n+1];
    for(int i=0;i<m;i++)
    {
        int n1=g[i].first.first;
        int n2=g[i].first.second;
        int w=g[i].second;
        adjLis[n1].push_back({n2,w});
        adjLis[n2].push_back({n1,w});
    }


    vector<pair<pair<int,int>,int>>ans;//{1,2},w
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>vis(n+1,0);

    pq.push({0,{1,-1}});
    while(!pq.empty())
    {
        int node=pq.top().second.first;
        int parent=pq.top().second.second;
        int w=pq.top().first;
        pq.pop();
        if(vis[node]==1) continue;
        vis[node]=1;
        if(parent!=-1)
        ans.push_back({{node,parent},w});

        for(auto it:adjLis[node])
        {
            int vertex=it.first;
            int wt=it.second;
            if(vis[vertex]==0)
            {
                pq.push({wt,{vertex,node}});
            }
        }
    }
    return ans;

}
