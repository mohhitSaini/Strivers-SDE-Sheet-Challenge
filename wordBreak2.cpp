#include <bits/stdc++.h> 

bool isPossible(string s,vector<string>&dictionary)
{
    for(int i=0;i<dictionary.size();i++)
    {
        if(dictionary[i]==s)
        return true;
    }
}

void solve(int index,string s,vector<string>&str,vector<string>&dictionary,vector<string>&ans,int len)
{
    //base case
    if(index==len)
    {
        string sentence="";
        for(auto it:str)
        sentence+=it+" ";
        ans.push_back(sentence);
        return;
    }

    for(int i=0;i<s.length();i++)
    {
        if(isPossible(s.substr(0,i+1),dictionary))
        {
            str.push_back(s.substr(0,i+1));
            solve(index+i+1,s.substr(i+1),str,dictionary,ans,len);
            str.pop_back();
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>ans;
    vector<string>str;
    solve(0,s,str,dictionary,ans,s.length());
    return ans;

}