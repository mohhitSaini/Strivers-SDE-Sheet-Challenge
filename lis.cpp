#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    int len=1;
    vector<int>vec;
    vec.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>vec[vec.size()-1])
        vec.push_back(arr[i]);
        else
        {
            int ind =lower_bound(vec.begin(),vec.end(),arr[i])-vec.begin();
            vec[ind]=arr[i];
        }
    }
    return vec.size();
}
