#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>weights(n+1,1000000000);
    weights[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(weights[u]+wt<weights[v]&&weights[u]!=1000000000)
            {
                weights[v]=weights[u]+wt;
            }
        }
    }
    return weights[dest];
}