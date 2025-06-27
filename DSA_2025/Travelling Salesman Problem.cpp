
class Solution {
  public:
  void totalCost(vector<vector<int>>&cost,vector<bool>&visited,int currPos,int n,int count, int costSoFar,int &ans) {

    // If all nodes are visited and there's an edge to
    // start node
    if (count == n && cost[currPos][0]) {
        // Update the minimum cost
        ans = min(ans, costSoFar + cost[currPos][0]);
        return;
    }
    // Try visiting each node from current position
    for(int i = 0; i < n; i++) {
        if(!visited[i] && cost[currPos][i]) {
            // If node not visited and has an edge
            // Mark as visited
            visited[i] = true;
            totalCost(cost,visited,i,n,count+1,costSoFar+cost[currPos][i],ans);
            visited[i]=false;
        }
    }
}
    int tsp(vector<vector<int>>& cost) {
        // Code here
        int n=cost.size();
    vector<bool>visited(n,false);
    visited[0] = true;
    int ans = INT_MAX;
    totalCost(cost, visited, 0, n, 1, 0, ans);
    return ans;
    }
};


class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // Code here
       // Number of nodes
    int numNodes = cost.size();
    vector<int> nodes;

    // Initialize the nodes excluding the fixed 
   // starting point (node 0)
    for (int i = 1; i < numNodes; i++)
        nodes.push_back(i);

    int minCost = INT_MAX;

    // Generate all permutations of the remaining nodes
    do {
        int currCost = 0;

        // Start from node 0
        int currNode = 0;

        // Calculate the cost of the current permutation
        for (int i = 0; i < nodes.size(); i++) {
            currCost += cost[currNode][nodes[i]];
            currNode = nodes[i];
        }

        // Add the cost to return to the starting node
        currCost += cost[currNode][0];

        // Update the minimum cost if the current cost 
      // is lower
        minCost = min(minCost, currCost);

    } while (next_permutation(nodes.begin(), nodes.end()));

    return minCost;
    }
};


class Solution {
  public:
  int totalCost(int mask, int pos, int n, vector<vector<int>> &cost) {
  
    // Base case: if all cities are visited, return the 
   // cost to return to the starting city (0)
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    int ans = INT_MAX;

    // Try visiting every city that has not been visited yet
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
          
            // If city i is not visited, visit it and update the mask
            ans = min(ans, cost[pos][i] + 
                      totalCost((mask | (1 << i)), i, n, cost));
        }
    }
    return ans;
  }
    int tsp(vector<vector<int>>& cost) {
        // Code here
      int n = cost.size();
  
  // Start from city 0, and only city 0 is visited initially (mask = 1)
    return totalCost(1, 0, n, cost);  
    }
};


class Solution {
  public:
  int totalCost(int mask, int curr, int n, 
              vector<vector<int>> &cost, vector<vector<int>> &memo) {
    
   // Base case: if all cities are visited, return the
    // cost to return to the starting city (0)
    if (mask == (1 << n) - 1) {
        return cost[curr][0];
    }

    if (memo[curr][mask] != -1)
        return memo[curr][mask];

    int ans = INT_MAX;

    // Try visiting every city that has not been visited yet
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
          
            // If city i is not visited, visit it and update 
           // the mask
            ans = min(ans, cost[curr][i] + 
                      totalCost((mask | (1 << i)), i, n, cost, memo));
        }
    }

    return memo[curr][mask] = ans;
}
    int tsp(vector<vector<int>>& cost) {
        // Code here
      int n = cost.size();
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));
  
    // Start from city 0, and only city 0 is visited
  	// initially (mask = 1)
    return totalCost(1, 0, n, cost,
                     memo);  
    }
};

Version	                       Time Complexity	                          Space Complexity
1. DFS with visited	           O(n!)	                                    O(n)
2. next_permutation	           O(n! * n)	                                O(n)
3. Bitmask DP (no memo)	       Exponential (>2ⁿ)	                        O(n)
4. Bitmask DP + memo (Best)	   ✅ O(n² * 2ⁿ)	                            ✅ O(n * 2ⁿ)

