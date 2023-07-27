#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int n, int source) {
    vector<vector<pair<int,int>>>adjLis(vertices);
    vector<int>weights(vertices,INT_MAX);
    weights[source]=0;
    for(int i=0;i<n;i++)
    {
        adjLis[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adjLis[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({source,0});
    // vector<int>vis(vertices,0);
    vis[source]=1;
    while(!pq.empty())
    {
        int node=pq.top().first;
        vis[node]=1;
        int w=pq.top().second;
        pq.pop();
        for(auto it:adjLis[node])
        {
            if(w+it.second<weights[it.first])
            {
                weights[it.first]=w+it.second;
                pq.push({it.first,w+it.second});
            }
        }
    }
    return weights;
}
