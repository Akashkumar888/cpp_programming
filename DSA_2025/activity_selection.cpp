
int activitySelection(vector<int> &start, vector<int> &finish) {
  int n = start.size();
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
      ans.push_back({start[i], finish[i]});
  }
  sort(ans.begin(), ans.end());
  int cnt = 1;
  int last_time = ans[0].second;
  for (int i = 1; i < ans.size(); i++) {
      if (last_time >= ans[i].first) {
          last_time = min(last_time, ans[i].second);
          continue;
      } else {
          cnt++;
          last_time = max(last_time, ans[i].second);
      }
  }
  return cnt;
}
