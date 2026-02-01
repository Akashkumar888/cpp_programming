
class{
public:
int kBitFlips(vector<int> &arr, int k) {
    int n = arr.size(); 
    int res = 0, flag = 0;
    queue<int> q; 

    for (int i = 0; i < n; i++) {
        
        if(i >= k) {
            flag ^= q.front();
            q.pop();
        }
        
        // If flag = 1, then flip the current index
        if(flag == 1)
            arr[i] ^= 1;
        
        // Finally, if arr[i] = 0, then we need to flip
        if(arr[i] == 0) {
            
            // Check if k elements are left
            if(i + k > n) 
                return -1;
            
            res += 1;
            
            // Flip flag so that upcoming elements are also flipped
            flag ^= 1;
            
            // If we flip, push 1 to the queue
            q.push(1);
        }
        else {
            
            // If we don't flip, push 0 to queue
            q.push(0);
        }
    }

    return res; 
}
};