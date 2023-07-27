#include <bits/stdc++.h> 

class DisjointSet{
	public:
	vector<int>rank;
	vector<int>parent;
	DisjointSet(int n)
	{
		parent.resize(n+1,0);
		rank.resize(n+1,1);
		for(int i=0;i<=n;i++)
		{
			parent[i]=i;
		}
	}
	int findParent(int vertex)
	{
		if(parent[vertex]==vertex)
		return vertex;
		return parent[vertex]=findParent(parent[vertex]);
	}

	void unionByRank(int u,int v)
	{
		int u_p=parent[u];
		int v_p=parent[v];

		if(rank[u_p]>rank[v_p])
		{
			parent[v_p]=parent[u_p];
		}
		else if(rank[v_p]>rank[u_p])
		{
			parent[u_p]=parent[v_p];
		}
		else
		{
			parent[u_p]=parent[v_p];
			rank[u_p]++;
		}
	}

};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	DisjointSet ds(n);
	int ans=0;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
	for(int i=0;i<m;i++)
	{
		pq.push({graph[i][2],{graph[i][1],graph[i][0]}});
	}
	while(!pq.empty())
	{
		int node1=pq.top().second.first;
		int node2=pq.top().second.second;
		int wt=pq.top().first;
		pq.pop();
		if(ds.findParent(node1)==ds.findParent(node2)) continue;
		else
		{
			ans+=wt;
			ds.unionByRank(node1,node2);
		}
	}
	return ans;

}