
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // Step 1: Sort the citations
        sort(citations.begin(), citations.end());
        
        // Step 2: Check condition
        for (int i = 0; i < n; i++) {
            int papers = n - i;   // papers with >= citations[i]
            
            if (citations[i] >= papers)
                return papers;
        }
        
        return 0;
    }
};



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // Step 1: Create frequency array
        vector<int> freq(n + 1, 0);
        
        for (int c : citations) {
            if (c >= n)
                freq[n]++;
            else
                freq[c]++;
        }

        // Step 2: Convert to cumulative count
        for (int i = n - 1; i >= 0; i--) {
            freq[i] += freq[i + 1];
        }

        // Step 3: Binary Search
        int low = 0, high = n, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (freq[mid] >= mid) {
                ans = mid;        // valid h
                low = mid + 1;    // try bigger
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};


class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        // The H-index is a, "Hirsch index" metric measuring a researcher's productivity and citation impact, defined as the maximum number such that they have published at least papers, each cited at least times. It balances output (number of papers) and impact (citations), offering a robust alternative to simple citation counts
        int n=citations.size();
        // Step 1: Frequency array
        vector<int>freq(n+1,0);
        
        for (int i = 0; i < n; i++) {
            if(citations[i] >= n)freq[n]++;
            else freq[citations[i]]++;
        }

        // Step 2: Start from maximum possible H
        int Hindex=n;
        int num=freq[n];   // papers with >= n citations
        
        while (Hindex > num) {
            Hindex--;
            num += freq[Hindex];
        }
        return Hindex;
    }
};


class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        // The H-index is a, "Hirsch index" metric measuring a researcher's productivity and citation impact, defined as the maximum number such that they have published at least papers, each cited at least times. It balances output (number of papers) and impact (citations), offering a robust alternative to simple citation counts
        int n=citations.size();
        // Step 1: Frequency array
        vector<int>freq(n+1,0);
        
        for (int i = 0; i < n; i++) {
            if(citations[i] >= n)freq[n]++;
            else freq[citations[i]]++;
        }

        // Step 2: Start from maximum possible H
        int last=freq[n];   // papers with >= n citations
        
        for(int i=n-1;i>=0;i--){
            if(last>=i+1)return i+1;
            last+=freq[i];
        }
        return 0;
    }
};

