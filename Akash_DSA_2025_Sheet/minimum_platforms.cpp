
int minPlatforms(vector<int>& arr, vector<int>& dep) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  sort(dep.begin(), dep.end());

  int i = 0, j = 0;
  int maxplat = 0, cnt = 0;

  while (i < n && j < n) {
      if (arr[i] <= dep[j]) {
          cnt++;
          maxplat = max(maxplat, cnt);
          i++;
      } else {
          cnt--;
          j++;
      }
  }
  return maxplat;
}
