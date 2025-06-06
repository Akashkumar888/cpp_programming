
class Solution {
  public:
  void solve(string &pat,int m,vector<int>&LPS){
       int len = 0;
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
  }
    vector<int> search(string &pat, string &txt) {
        // code here.
        // lps lagao pat pr 
        int m=pat.size();
        int n=txt.size();
        vector<int>LPS(m,0);
        //yaha pr lps lagao
        solve(pat,m,LPS);
        
        // phir txt me lps dhudn lo
        vector<int>ans;
        int i=0,j=0;
        while(j<n){
            if(pat[i]==txt[j]){
                i++,j++;
            }
            if(i==m){
                ans.push_back(j-i+1);
                i=LPS[i-1];
            }
            else if(pat[i]!=txt[j]){
                if(i==0)j++;
                else i=LPS[i-1];
            }
        }
        return ans;
    }
};




class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
       const int d = 256;       // number of characters in input alphabet (ASCII)
        const int q = 101;       // a prime number for mod (to reduce hash collisions)

        int m = pat.size();
        int n = txt.size();

        vector<int> ans;         // to store 1-based indices of matches

        if (m > n) return ans;

        int p = 0; // hash value for pattern
        int t = 0; // hash value for text
        int h = 1;

        // The value of h would be "pow(d, m-1)%q"
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Calculate the hash value of pattern and first window of text
        for (int i = 0; i < m; i++) {
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {
            // If hash values match, then check characters one by one
            if (p == t) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    ans.push_back(i + 1); // 1-based indexing
                }
            }

            // Calculate hash value for next window
            if (i < n - m) {
                t = (d * (t - txt[i] * h) + txt[i + m]) % q;
                if (t < 0) t += q;
            }
        }

        return ans;
    }
};

