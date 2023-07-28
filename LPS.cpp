#include <bits/stdc++.h>
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.length();
	vector<int>lps(2*n+1,0);
	int len=0;
	int i=1;
	string s=str;
	reverse(str.begin(),str.end());
	s+="&"+str;
	while(i<s.length())
	{
		if(s[i]==s[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	return n-lps[s.length()-1];
}
