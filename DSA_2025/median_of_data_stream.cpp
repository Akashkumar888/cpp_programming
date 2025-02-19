
vector<double> getMedian(vector<int> &arr) {
  priority_queue<int> left; // Max-heap for the smaller half
  priority_queue<int, vector<int>, greater<int>> right; // Min-heap for the larger half
  vector<double> ans;
  
  for (int num : arr) {
      // Step 1: Insert into appropriate heap
      if (left.empty() || num < left.top()) {
          left.push(num);
      } else {
          right.push(num);
      }

      // Step 2: Balance the heaps
      if (left.size() > right.size() + 1) {
          right.push(left.top());
          left.pop();
      } else if (left.size() < right.size()) {
          left.push(right.top());
          right.pop();
      }

      // Step 3: Compute median
      if (left.size() == right.size()) {
          ans.push_back((left.top() + right.top()) / 2.0);
      } else {
          ans.push_back(left.top());
      }
  }
  return ans;
}
