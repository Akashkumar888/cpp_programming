
int findDuplicate(vector<int>& arr) {
  int n = arr.size();
  int XOR = 0;
  for(int i = 1; i < n; i++) 
      XOR ^= i;
  for(int &num : arr) 
      XOR ^= num;
  return XOR;
}


int findDuplicate(vector<int>& arr) {
  // code here
  int n=arr.size();
  long long nthSum=(long long)(n-1)*n/2;
  long long sum=0;
  for(int &num:arr)sum+=num;
  return int(sum-nthSum);
}

