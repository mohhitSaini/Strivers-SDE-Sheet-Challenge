#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(101,0);
        int maxElement=0;
                   int a;
                   bool flag=true;
        for(int i=0;i<n;i++)
        {
 
            cin>>a;
            if(a>maxElement)
            maxElement=a;
            vec[a]++;
        }
        for(int i=0;i<=a;i++)
        {
            if(vec[i+1]>vec[i])
            {
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }
        if(flag)
        cout<<"YES"<<endl;
    }
}