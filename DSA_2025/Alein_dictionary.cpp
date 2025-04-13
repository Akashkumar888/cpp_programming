
string findOrder(vector<string> &words) {
  int n = words.size();
  string result = "";
  vector<int> indegree(26, 0);
  vector<bool> present(26, false);

  for (auto &word : words) {
      for (auto &ch : word) {
          present[ch - 'a'] = true;
      }
  }

  unordered_map<int, vector<int>> adj;
  for (int i = 0; i < n - 1; i++) {
      string word1 = words[i];
      string word2 = words[i + 1];

      // Invalid case: word1 > word2 but word2 is a prefix
      if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
          return "";

      int l = 0, r = 0;
      while (l < word1.size() && r < word2.size()) {
          if (word1[l] != word2[r]) {
              adj[word1[l] - 'a'].push_back(word2[r] - 'a');
              indegree[word2[r] - 'a']++;
              break;
          }
          l++, r++;
      }
  }

  queue<int> q;
  for (int i = 0; i < 26; i++) {
      if (present[i] && indegree[i] == 0)
          q.push(i);
  }

  while (!q.empty()) {
      int curr = q.front();
      q.pop();
      result += char(curr + 'a');

      for (auto &ngbr : adj[curr]) {
          indegree[ngbr]--;
          if (indegree[ngbr] == 0)
              q.push(ngbr);
      }
  }

  // Validate result: must include all present characters
  for (int i = 0; i < 26; i++) {
      if (present[i] && result.find(char(i + 'a')) == string::npos)
          return "";
  }

  return result;
}
