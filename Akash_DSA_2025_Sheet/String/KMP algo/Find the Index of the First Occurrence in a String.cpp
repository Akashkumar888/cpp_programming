

// 1️⃣ KMP (Knuth–Morris–Pratt) Algorithm
// 🔹 Idea
// KMP avoids re-checking characters by using LPS array (Longest Prefix which is also Suffix).
// 🔹 What is LPS?
// For each position i in pattern:
// Length of the longest proper prefix which is also a suffix ending at i.
// Example:
// Pattern = "abab"
// LPS = [0,0,1,2]
// 🔹 How KMP Works
// Precompute LPS array for the pattern.
// Compare pattern with text:
// If characters match → move both pointers.
// If mismatch → shift pattern using LPS, not from start.
// This avoids unnecessary comparisons.
// 🔹 Time & Space Complexity
// Time: O(n + m)
// Space: O(m) for LPS array
// 🔹 Where KMP Is Used
// ✔️ Substring search (strStr, find)
// ✔️ DNA sequence matching
// ✔️ Plagiarism detection
// ✔️ Search engines
// ✔️ Competitive programming




class Solution {
public:
    void KMP(string &needle,vector<int>&lps){
      int pre=0,suf=1;
      while(suf<needle.size()){
        if(needle[pre]==needle[suf]){
            lps[suf]=pre+1;
            pre++,suf++;
        }
        else{
            if(pre==0) {
                lps[suf]=0;
                suf++;
            }
            else{
                pre=lps[pre-1];
            }
        }
      }
 }
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
        int i=0,j=0;
        vector<int>lps(n,0);
        KMP(needle,lps);
        while(i<m && j<n){
        if(haystack[i]==needle[j]){
            i++,j++;
        }
        else {
            if(j==0){
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
        }
        if(j==n)return i-j;
        return -1;
    }
};



class Solution {
public:
    int strStr(string txt, string pat) {
    int m=pat.size();
    int n=txt.size();
    int ans=-1;
    int i=1,len=0;
    vector<int>lps(m);
    lps[0]=0;
    while(i<m){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
                len=lps[len-1];
            }
        }
    }
    int l=0,r=0;
    while(l<n){
        if(txt[l]==pat[r]){
            l++;
            r++;
        }
        if(r==m){
            ans=(l-r);
            r=lps[r-1];
            break;
        }
        else if(txt[l]!=pat[r]){
            if(r==0){
                l++;
            }
            else r=lps[r-1];
        }
    }
    return ans;
    }
};





class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
    int m=needle.size();
    for(int i=0;i<=n-m;i++){
        int first=i,second=0;
        while(second<m){
        if(haystack[first]!=needle[second]){
            break;
        }
        else{
            first++,second++;
        }
        }
        if(second==m){
            return i;
        }
    }
       return -1;
    }
};

