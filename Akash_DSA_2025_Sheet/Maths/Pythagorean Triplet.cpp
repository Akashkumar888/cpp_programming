
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)st.insert(arr[i]);
        
        for(int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
              	int a=arr[i];
              	int b=arr[j];
                int c=sqrt(a * a + b * b);
                
                if (st.find(c)!=st.end() && c*c==a*a + b*b)return true;
            }
        }
        return false;
    }
};

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
    int maxEle = 0;
    for (int ele: arr) 
        maxEle = max(maxEle, ele);

    // Visited array to mark the elements
    vector<bool> vis(maxEle + 1, 0);

    // Marking each element of input array
    for (int ele: arr)
        vis[ele] = true;

    // Iterate for all possible a
    for (int a = 1; a < maxEle + 1; a++) {

        // If a is not there
        if (vis[a] == false)
            continue;

        // Iterate for all possible b
        for (int b = 1; b < maxEle + 1; b++) {

            // If b is not there
        	if (vis[b] == false)
            	continue;

            // calculate c value to form a pythagorean triplet
            int c = sqrt(a * a + b * b);

            // If c^2 is not a perfect square or c exceeds the
          	// maximum value
            if ((c * c) != (a * a + b * b) || c > maxEle)
                continue;

            // If there exists c in the original array,
            // we have found the triplet
            if (vis[c] == true) {
                return true;
            }
        }
    }
    return false;
    }
};


class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n = arr.size();
  
      	// Taking Square of each element
        for (int i = 0; i < n; i++)arr[i] = arr[i] * arr[i];
        
        sort(arr.begin(), arr.end());
    
        // fix the largest element of Pythagorean triplet
        for (int i = n - 1; i > 1; i--) {
    
            // Two pointer technique to find remaining two 
            // elements such that a^2 + b^2 = c^2
            int l = 0;
            int r = i - 1;
            while (l < r) {
    
                // A Pythagorean triplet is found
                if (arr[l] + arr[r] == arr[i]) return true;
    
                if (arr[l] + arr[r] < arr[i])l++;
               	else  r--;
            }
        }
    return false;
    }
};
