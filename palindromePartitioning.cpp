#include <bits/stdc++.h> 

bool isPalindrome(int i,int j,string str)
{
    while(i<=j)
    {
        if(str[i]!=str[j])
        return false;
        i++;
        j--;
    }
    return true;
}

void solve(int index,string str,vector<vector<string>>&ans,vector<string>&temp)
{
    if(index==str.length())
    {
        ans.push_back(temp);
        return;
    }

    for(int i=index;i<str.length();i++)
    {
        if(isPalindrome(index,i,str))
        {
            temp.push_back(str.substr(index,i-index+1));
            solve(i+1,str,ans,temp);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>temp;
    solve(0,s,ans,temp);
    return ans;
    
}