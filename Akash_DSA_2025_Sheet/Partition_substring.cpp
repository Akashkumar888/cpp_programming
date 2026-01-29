
int maxPartitions(string &s) {
  int n = s.size();
  vector<int> mp(26, 0);

  // Store the last occurrence of each character
  for (int i = 0; i < n; i++) {
      mp[s[i] - 'a'] = i;
  }

  int cnt = 0, end = 0, i = 0;

  // Iterate through the string to form partitions
  while (i < n) {
      end = max(end, mp[s[i] - 'a']);
      if (i == end) {
          cnt++;  // Partition is completed
      }
      i++;
  }

  return cnt;
}
