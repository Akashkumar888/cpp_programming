
int missingNum(vector<int>& arr) {
  int n = arr.size();
  int missing = 0;
  for(int i = 1; i <= n + 1; i++) 
      missing = missing ^ i;
  for(int &num : arr) 
      missing = missing ^ num;
  return missing;
}
