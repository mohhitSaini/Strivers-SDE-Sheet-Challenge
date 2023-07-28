#include <bits/stdc++.h>

bool isPossible(string s,vector<string>&arr)
{
    int count=0;
    int len=s.length();
    for(int i=0;i<arr.size();i++)
    {
        if(s==arr[i].substr(0,len))
        count++;
    }
    if(count==arr.size())
    return true;
    return false;
}



string longestCommonPrefix(vector<string> &arr, int n)
{
    pair<int,string>minLen;
    minLen={1000,""};
    for(int i=0;i<arr.size();i++)
    {
        int len=minLen.first;
        string s=minLen.second;
        if(arr[i].length()<len)
        {
            len=arr[i].length();
            s=arr[i];
        }
        minLen={len,s};
    }
    string s=minLen.second;
    int len=minLen.first;
    int start=0,end=len-1;
    string ans="";
    while(start<=end)
    {
        int i=(start+end)/2;
        if(isPossible(s.substr(0,i+1),arr)==true)
        {
            ans= s.substr(0,i+1);
            start=i+1;
        }
        else
        {
            end=i-1;
        }
    }
    return ans;
}


