#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    if(n==0)
    return 0;
    long long int maxSum=0;
    long long int currSum=0;

    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        if(currSum>maxSum)
        maxSum=currSum;

        if(currSum<0)
        {
            currSum=0;
        }
    }
    return maxSum;
}