
class Solution {
  public:
    int kBitFlips(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        int times=0,ans=0;
        vector<int>flipped(n,0);
        for(int i=0;i<n;i++){
            if(i-k>=0){
                times-=flipped[i-k];
            }
            if((nums[i]==1&&times%2==1) || (nums[i]==0&&times%2==0)){
                if(i+k>n)return -1;
                times++;
                ans++;
                flipped[i]=1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int times=0,ans=0;
        for(int i=0;i<n;i++){
            if(i-k>=0){
                if(nums[i-k]>1){
                    nums[i-k]=nums[i-k]-2;
                    times--;
                }
            }
            if((nums[i]==1&&times%2==1) || (nums[i]==0&&times%2==0)){
                if(i+k>n)return -1;
                times++;
                ans++;
                nums[i]+=2;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int times=0,ans=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(i-k>=0 && !q.empty()){
                times-=q.front();
                q.pop();
            }
            if((nums[i]==1&&times%2==1) || (nums[i]==0&&times%2==0)){
                if(i+k>n)return -1;
                times++;
                ans++;
                q.push(1);
            }
            else q.push(0);
        }
        return ans;
    }
};

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int times = 0, ans = 0;
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            // if past a flip window, remove it
            if (!q.empty() && q.front() < i) {
                times--;
                q.pop();
            }
            
            // check if we need a flip
            if ((nums[i] == 1 && times % 2 == 1) || 
                (nums[i] == 0 && times % 2 == 0)) {
                
                if (i + k > n) return -1;  // not enough space to flip
                
                times++;
                ans++;
                q.push(i + k - 1);  // flip ends at index i+k-1
            }
        }
        return ans;
    }
};

