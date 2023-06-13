#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int count=1;
	int index=0;
	for(int i=1;i<n;i++)
	{
		if(arr[index]==arr[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(!count)
		{
			index=i;
			count=1;
		}
	}
	count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==arr[index])
		count++;
	}
	if(count>n/2)
	return arr[index];
	return -1;
}