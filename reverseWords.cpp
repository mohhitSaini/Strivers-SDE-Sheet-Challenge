#include <bits/stdc++.h>
string reverseString(string &str){
		stack<string>st;
		string s="";
		for(int i=0;i<str.length();i++)
		{
			if(str[i]==' ')
			{
				if(s!="")
				st.push(s);
				s="";
			}
			else
			{
				s+=str[i];
			}
		}
		if(s!="")
		st.push(s);
		string ans="";
		while(!st.empty())
		{
			ans+=st.top();
			st.pop();
			if(st.empty()) continue;
			ans+=" ";
		}
		return ans;
}