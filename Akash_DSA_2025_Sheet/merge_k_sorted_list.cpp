
Node* mergeKLists(vector<Node*>& arr) {
  priority_queue<int, vector<int>, greater<int>> pq;
  int n = arr.size();

  // Step 1: Push all elements into the min-heap
  for (int i = 0; i < n; i++) {
      Node* curr = arr[i];
      while (curr) {
          pq.push(curr->data);
          curr = curr->next;
      }
  }

  // Step 2: Construct the sorted merged list
  Node* dummy = new Node(-1);
  Node* temp = dummy;

  while (!pq.empty()) {
      int val = pq.top();
      pq.pop();
      temp->next = new Node(val);
      temp = temp->next;
  }

  return dummy->next;
}
