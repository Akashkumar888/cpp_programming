
// ✅ Boyer-Moore Voting Algorithm 

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        // Moore's Voting Algorithm
        int n=arr.size();
        int maj=arr[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(maj==arr[i]) count++;
            else if(count==0){
                maj=arr[i];
                count=1;
            }
            else{
                count--;
            }
        }
        int freq=0;
        for(int i=0;i<n;i++){
            if(arr[i]==maj)freq++;
        }
        if(freq>floor(n/2))return maj;// strictly more than arr.size()/2 times 
        return -1;
    }
};




class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        // ✅ Boyer-Moore Voting Algorithm  
        // (Extended Boyer-Moore Voting Algorithm)
        int n=arr.size();
        int count1=0;
        int count2=0;
        int maj1=-1;
        int maj2=-1;
        // first find number 
        for(int i=0;i<n;i++){
            if(maj1==arr[i])count1++;
            else if(maj2==arr[i])count2++;
            else if(count1==0){
                    maj1=arr[i];
                    count1=1;
                }
            else if(count2==0){
                    maj2=arr[i];
                    count2=1;
                }
            else{
                count1--;
                count2--;
            }
        }
        // verifications 
        int freq1=0,freq2=0;
        for(int i=0;i<n;i++){
            if(maj1==arr[i])freq1++;
            else if(maj2==arr[i])freq2++;
        }
        vector<int>ans;
        if(freq1>floor(n/3))ans.push_back(maj1);//greater than one-third of the total
        if(freq2>floor(n/3))ans.push_back(maj2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


// ✅ Time Complexity: O(n)
// The algorithm consists of two linear passes through the array:
// First pass to find potential candidates (O(n))
// Second pass to verify their frequencies (O(n))
// Sorting ans takes O(1) or O(2·log2) = constant time (since ans can have at most 2 elements).
// So overall:
// T(n) = O(n + n + log2) = O(n)

// ✅ Space Complexity: O(1)
// You are using only a constant number of extra variables (count1, count2, maj1, maj2, freq1, freq2).
// The output vector ans can have at most 2 elements, so this is constant auxiliary space.

