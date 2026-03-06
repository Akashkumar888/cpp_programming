
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)return '0';
        string s1="0";
        for(int i=2;i<=n;i++){
         string rev=s1;
         for(int j=0;j<rev.size();j++){
            if(rev[j]=='0')rev[j]='1';
            else rev[j]='0';
         }
         reverse(rev.begin(),rev.end());
         string str=s1+"1"+rev;
         s1=str;
        }
        return s1[k-1];
    }
};



class Solution {
public:
    char findKthBit(int n, int k) {
     string s1="0";
     while(n>1){
        string s2=s1 + "1" ;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='0')s1[i]='1';
            else s1[i]='0';
        }
        reverse(s1.begin(),s1.end());
        s2+=s1;
        s1=s2;
        n--;
     } 
     return s1[k-1];
    }
};



// 🧠 Key Observation (Very Important)
// Length of Sn:
// len = 2^n - 1
// Structure:
// Sn = S(n-1) + "1" + reverse(invert(S(n-1)))
// So it looks like:
// [ Left ] [ Middle ] [ Right ]
// Where:
// Left → S(n-1)
// Middle → always '1'
// Right → reverse(invert(S(n-1)))

// 🔥 Important Pattern
// Middle index:
// mid = 2^(n-1)
// Because:
// Total length = 2^n - 1
// Middle = (length + 1) / 2
//  = 2^(n-1)
// 🧠 Core Idea
// If we want kth bit:
// Case 1:
// If k == mid
// → answer = '1'
// Case 2:
// If k < mid
// → same as findKthBit(n-1, k)
// Case 3:
// If k > mid
// Then it lies in right half.
// Right half is:
// reverse(invert(S(n-1)))
// Because of reverse:
// New index becomes:
// newK = 2^n - k
// And because of invert:
// Final answer = opposite of findKthBit(n-1, newK)



class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;

        if(k == mid) 
            return '1';

        else if(k < mid)
            return findKthBit(n - 1, k);

        else {
            char ch = findKthBit(n - 1, len - k + 1);
            return (ch == '0') ? '1' : '0';
        }
    }
};