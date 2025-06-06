
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
       // Number of characters in the input alphabet (ASCII)
    int d = 256;
    // A prime number for modulo operations to reduce collisions
    int q = 101;
    // Length of the pattern
    int M = pat.length();
    // Length of the text
    int N = txt.length();
    // Hash value for pattern
    int p = 0;
    // Hash value for current window of text
    int t = 0;
    // High-order digit multiplier
    int h = 1;
    
    vector<int> ans;
    
    // Precompute h = pow(d, M-1) % q
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Compute initial hash values for pattern and first window of text
    for (int i = 0; i < M; i++){
        
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= N - M; i++){
        
        // If hash values match, check characters one by one
        if (p == t){
            bool match = true;
            for (int j = 0; j < M; j++){
                
                if (txt[i + j] != pat[j]){
                
                    match = false;
                    break;
                }
            }
            if (match)
                ans.push_back(i + 1);
        }

        // Calculate hash value for the next window
        if (i < N - M){
            
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // Ensure hash value is non-negative
            if (t < 0)
                t += q;
        }
    }
    return ans;
    }
};


