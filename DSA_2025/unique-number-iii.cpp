
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        // code here
        int number=0;
        for(int bit=0;bit<32;bit++){
            int cnt=0;
            for(int &num:arr){
                int set_bit=(1<<bit) & num;
                if(set_bit)cnt++;
            }
            if(cnt%3)number=(1<<bit) | number;
        }
        return number;
    }
  };