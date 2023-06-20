int NthRoot(int n, int m) {
  int start=0,end=m/n;
  int mid;
  while(start<=end)
  {
    mid=start+(end-start)/2;
    if(pow(mid,n)==m)
    {
      return mid;
    }
    else if(pow(mid,n)<m)
    {
      start=mid+1;
    }
    else
    {
      end=mid-1;
    }
  }
  return -1;

}