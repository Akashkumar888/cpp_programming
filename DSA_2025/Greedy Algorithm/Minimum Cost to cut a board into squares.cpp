
class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        // We need to cut it into 1×1 squares.
        // Sort descending
        priority_queue<pair<int,int>> pq;
        // 0 -> vertical cut, 1 -> horizontal cut
        for(auto i : x) pq.push({i, 0});
        for(auto i : y) pq.push({i, 1});

        int h_segments = 1, v_segments = 1;
        long long total_cost = 0; // use long long to avoid overflow

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            if(p.second == 0){ 
                // vertical cut
                total_cost += 1LL * p.first * h_segments;
                v_segments++;
            } else { 
                // horizontal cut
                total_cost += 1LL * p.first * v_segments;
                h_segments++;
            }
        }
        return (int)total_cost;
    }
};



class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        // We need to cut it into 1×1 squares.
        // Sort descending
    sort(x.begin(), x.end(),greater<int>());
    sort(y.begin(), y.end(),greater<int>());

    int i = 0, j = 0;
    int h_segments = 1, v_segments = 1;
    int total_cost = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] >= y[j]) {
            // Vertical cut
            total_cost += x[i] * h_segments;
            v_segments++;
            i++;
        } 
        else {
            // Horizontal cut
            total_cost += y[j] * v_segments;
            h_segments++;
            j++;
        }
    }
    // Remaining vertical cuts
    while (i < x.size()) {
        total_cost += x[i] * h_segments;
        i++;
    }
    // Remaining horizontal cuts
    while (j < y.size()) {
        total_cost += y[j] * v_segments;
        j++;
    }
    return total_cost;
    }
};



class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        // We need to cut it into 1×1 squares.
        //sort because the larger cost will be incurred for the least number of segment to cut.
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int min_cost = 0;
        int horizontalSegment = 1;
        int verticalSegment = 1;
        int x_len = m-1;
        int y_len = n-1;
        int i = x_len-1;
        int j = y_len - 1;
        
        //iterate in reverse order and check which cost is larger and incurr that
        while(i>=0 && j>=0){
            if(x[i]>=y[j]){
                min_cost+=(x[i]*horizontalSegment);
                verticalSegment++;
                i--;
            }
            else
            {
                min_cost+=(y[j]*verticalSegment);
                horizontalSegment++;
                j--;
            }
        }
        //check whether n*m cells have been cut or not.
        while(i>=0){
            min_cost+=(x[i]*horizontalSegment);
            verticalSegment++;
            i--;
        }
        while(j>=0){
            min_cost+=(y[j]*verticalSegment);
            horizontalSegment++;
            j--;
        }
        //return the minimum cost.
        return min_cost;
    }
};

