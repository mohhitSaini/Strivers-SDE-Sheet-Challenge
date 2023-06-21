#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
     int n=arr.size(); 
     int curXor=0;
     map<int,int>mp;
     mp[0]=1;
     int x=0,ans=0;
     for(int i=0;i<n;i++)
     {
         curXor^=arr[i];
         x=curXor^k;
         if(mp.find(x)!=mp.end())
         {
             ans+=mp[x];
         }
         mp[curXor]++;
     }
     return ans;
}