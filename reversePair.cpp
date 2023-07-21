#include <bits/stdc++.h> 

void merge(int low, int mid, int high, vector<int>& arr) {
    int len1 = mid - low + 1;
    int len2 = high - mid;
    vector<int> arr1(len1);
    vector<int> arr2(len2);
    
    // Copy elements from arr to arr1 and arr2
    for (int i = 0; i < len1; i++) {
        arr1[i] = arr[low + i];
    }
    for (int i = 0; i < len2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }
    
    vector<int> temp;
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
        } else {
            temp.push_back(arr2[j]);
            j++;
        }
    }
    while (i < len1) {
        temp.push_back(arr1[i]);
        i++;
    }
    while (j < len2) {
        temp.push_back(arr2[j]);
        j++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countAns(int low,int mid,int high,vector<int>&arr)
{
	int count=0;
	int j=mid+1;
	for(int i=low;i<=mid;i++)
	{
		while(j<=high&&arr[i]>2*arr[j])
		{
			j++;
		}
		count+=(j-(mid+1));
	}
	return count;
}

int mergeSort(int low,int high,vector<int>&arr)
{
	int count=0;
	if(low>=high) return count;
	int mid=(low+high)/2;
	count+=mergeSort(low,mid,arr);
	count+=mergeSort(mid+1,high,arr);
	count+=countAns(low,mid,high,arr);
	merge(low,mid,high,arr);
	return count;
}

int reversePairs(vector<int> &arr, int n){
	return mergeSort(0,n-1,arr);
	
}