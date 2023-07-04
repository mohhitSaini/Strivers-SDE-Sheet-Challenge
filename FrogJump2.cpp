#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>vec(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=abs(vec[1]-vec[0]);
    for(int i=2;i<=n;i++)
    {
        int toStore=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                toStore=min(toStore,dp[i-j]+abs(vec[i]-vec[i-j]));
            }
            dp[i]=toStore;
        }
    }
    cout<<dp[n-1];
}