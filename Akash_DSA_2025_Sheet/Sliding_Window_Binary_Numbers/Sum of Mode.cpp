
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        typedef pair<int,int> P;
        int n = arr.size();
        unordered_map<int,int> mp;
        // Comparator: larger freq first, smaller num if tie
        auto cmp = [&](P p1,P p2){// never use & in this line 
            if(p1.first == p2.first) return p1.second < p2.second;// smaller number if freq same
            return p1.first > p2.first;// larger frequency first
        };
        set<P, decltype(cmp)>s(cmp);
        // Build initial frequency map
        // sliding window part 
        for(int i=0; i<k; i++){
            mp[arr[i]]++;
        }
        // Insert all frequencies into set
        for(auto &it: mp)s.insert({it.second, it.first});

        int sum = (*s.begin()).second; // max freq element in first window
        int i = 0, j = k;
        while(j < n){
            int out = arr[i]; // element leaving the window
            int in = arr[j];  // element entering the window
            // Remove old freq of outgoing element
            s.erase({mp[out], out}); // remove old frequency from set
            mp[out]--;                // decrease frequency in map
            if(mp[out]>0)s.insert({mp[out], out}); // re-insert with new freq if > 0

            // Remove old freq of incoming element
            if(mp[in] > 0)s.erase({mp[in], in}); // remove old frequency if it exists
            mp[in]++;                  // increment frequency in map
            s.insert({mp[in], in});    // insert new frequency
            // Add max freq element to sum
            sum += (*s.begin()).second;
            i++;
            j++;
        }
        return sum;
    }
};

// Time: O(n log k)
// Space: O(k)




// P p1, P p2 passes by value, so copies of the pairs are made whenever the comparator is called.
// This is safe, but slightly less efficient than passing by reference because each comparison involves copying the pair<int,int>.
// If you want to avoid copies, you can pass by const reference:
// Passes by reference without copying.
// const ensures the comparator doesn’t modify the elements.
// Safe and standard-compliant for priority_queue, set, map, etc.
// ✅ Conclusion: For comparators, always use const & to avoid copies and keep safety.

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        typedef pair<int,int> P;
        int n = arr.size();
        unordered_map<int,int> mp;
        
        // Custom comparator: larger freq first, smaller num if tie
        auto cmp = [](const P &p1, const P &p2){
            if(p1.first != p2.first) return p1.first < p2.first;  // larger freq first
            return p1.second > p2.second;                         // smaller number first if tie
        };
        
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        
        // Build initial frequency map
        for(int i=0; i<k; i++) mp[arr[i]]++;
        // Push initial frequencies
        for(auto &it : mp) pq.push({it.second, it.first});
        
        int sum = pq.top().second;  // max freq element of first window
        
        int i=0,j=k;
        while(j < n){
            int out = arr[i];  // element leaving window
            int in = arr[j];   // element entering window
            
            // Update frequency map
            mp[out]--;
            mp[in]++;
            
            // Push new frequencies for outgoing and incoming elements
            pq.push({mp[out], out});
            pq.push({mp[in], in});
            
            // Remove stale top elements
            while(!pq.empty() && pq.top().first != mp[pq.top().second])pq.pop();
            
            // Add current mode to sum
            sum += pq.top().second;
            i++; 
            j++;
        }
        return sum;
    }
};



class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        typedef pair<int,int> P;
        int n = arr.size();
        unordered_map<int,int> mp;
        
        // Custom comparator: larger freq first, smaller num if tie
        auto cmp = [&](P p1,P p2){// never use here & 
            if(p1.first == p2.first)return p1.second > p2.second;// smaller number first if tie 
            return p1.first < p2.first;  // larger freq first
        };
        
        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);
        
        // Build initial frequency map
        for(int i=0; i<k; i++) mp[arr[i]]++;
        // Push initial frequencies
        // first window
        for(auto &it : mp) pq.push({it.second, it.first});
        
        int sum = pq.top().second;  // max freq element of first window
        // sliding window start 
        int i=0,j=k;
        while(j < n){
            int out = arr[i];  // element leaving window
            int in = arr[j];   // element entering window
            
            // Update frequency map
            mp[out]--;
            mp[in]++;
            
            // Push new frequencies for outgoing and incoming elements
            pq.push({mp[out], out});
            pq.push({mp[in], in});
            
            // Remove stale top elements
            while(!pq.empty() && pq.top().first != mp[pq.top().second])pq.pop();
            
            // Add current mode to sum
            sum += pq.top().second;
            i++; 
            j++;
        }
        return sum;
    }
};
