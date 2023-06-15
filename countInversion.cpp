#include <bits/stdc++.h> 
 void merge(long long *arr,int start,int mid,int end,int & count)
 {
     int len1=mid-start+1;
     int len2=end-mid;

     long long int* left=new long long int[len1];
     long long int* right=new long long int[len2];

     for(int i=0;i<len1;i++)
     {
         left[i]=arr[i+start];
     }

     for(int i=0;i<len2;i++)
     {
         right[i]=arr[i+mid+1];
     }  

     int i=0,j=0,k=start;
     while(i<len1&&j<len2)
     {
         if(left[i]<=right[j])
         {
             arr[k]=left[i];i++;
         }
         else{
             arr[k]=right[j];
             j++;
             count+=(len1-i);
         }
         k++;

     }
         while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }


 }   

 void mergeSort(long long *arr,int n,int start,int end,int & count)
{
    if(start>=end)
    return ;
    int mid=start+(end-start)/2;
    mergeSort(arr,n,start,mid,count);
    mergeSort(arr,n,mid+1,end,count);
    merge(arr,start,mid,end,count);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    int count=0;
    mergeSort(arr,  n, 0, n-1, count);
    return count;

}