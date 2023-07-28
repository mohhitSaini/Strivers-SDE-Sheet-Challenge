#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n=price.size();
    vector<int>arr(n,-1);
   stack<int>st;
   st.push(-1);
   for(int i=0;i<n;i++)
   {
       while(price[st.top()]<=price[i]&&st.top()!=-1)
       {
           st.pop();
       }
       arr[i]=st.top();
       st.push(i);
   }
   vector<int>ans;
   for(int i=0;i<n;i++)
   {
       ans.push_back(i-arr[i]);
   }
   return ans;
}