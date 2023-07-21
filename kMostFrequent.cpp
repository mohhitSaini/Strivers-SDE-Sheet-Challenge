#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(auto it:mp)
    {
        q.push({it.second,it.first});
        if(q.size()>k) q.pop();
    }
    vector<int>ans;
    while(!q.empty())
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}