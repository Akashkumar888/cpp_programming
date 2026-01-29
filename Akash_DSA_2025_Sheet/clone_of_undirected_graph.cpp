
void dfs(Node* &node, Node* &clone_node, map<Node*, Node*>& mp) {
  for (auto &ngbr : node->neighbors) {
      if (mp.find(ngbr) == mp.end()) {
          Node* clone = new Node(ngbr->val);
          mp[ngbr] = clone;
          clone_node->neighbors.push_back(clone);
          dfs(ngbr, clone, mp);
      } else {
          clone_node->neighbors.push_back(mp[ngbr]);
      }
  }
}

Node* cloneGraph(Node* node) {
  if (node == NULL) return NULL;

  map<Node*, Node*> mp;
  Node* clone_node = new Node(node->val);
  mp[node] = clone_node;

  dfs(node, clone_node, mp);
  return clone_node;
}
