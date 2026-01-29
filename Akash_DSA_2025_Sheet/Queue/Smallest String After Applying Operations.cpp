
string Solution::SmallestString(string A, int B, int C) {
    unordered_set<string> vis;
    queue<string> q;
    
    string ans = A;
    q.push(A);
    vis.insert(A);
    
    int n = A.size();
    
    while(!q.empty()){
        string s = q.front(); q.pop();
        ans = min(ans, s);
        
        // add operation on odd indices
        string t = s;
        for(int i = 1; i < n; i += 2){
            int d = (t[i] - '0' + C) % 10;
            t[i] = char('0' + d);
        }
        if(!vis.count(t)){
            vis.insert(t);
            q.push(t);
        }
        
        // rotate operation
        string r = s.substr(n - B) + s.substr(0, n - B);
        if(!vis.count(r)){
            vis.insert(r);
            q.push(r);
        }
    }
    
    return ans;
}
