
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
  typedef pair<int, int> P;
  int n = profit.size();
  vector<P> jobs;
  
  // Store jobs as (deadline, profit) pairs
  for (int i = 0; i < n; i++) 
      jobs.push_back({deadline[i], profit[i]});
  
  // Sort jobs by increasing deadline
  sort(jobs.begin(), jobs.end());
  
  // Min-heap to store job profits
  priority_queue<int, vector<int>, greater<int>> pq;
  
  for (int i = 0; i < n; i++) {
      if (jobs[i].first > pq.size()) {  
          pq.push(jobs[i].second);  // Add job if within deadline
      } else {
          if (!pq.empty() && jobs[i].second > pq.top()) {
              pq.pop();  // Remove lower profit job
              pq.push(jobs[i].second);  // Insert higher profit job
          }
      }
  }
  
  // Compute total jobs completed and max profit
  int maxJob = 0, maxProfit = 0;
  while (!pq.empty()) {
      maxJob++;
      maxProfit += pq.top();
      pq.pop();
  }
  
  return {maxJob, maxProfit};
}
