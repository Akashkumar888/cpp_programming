class Solution {
  public:
  string addStrings(string &s1,string &s2){
        string result="";
        int i=s1.size()-1,j=s2.size()-1,carry=0;
        while(i>=0||j>=0||carry){
            int sum=carry;
            if(i>=0)sum+=s1[i--]-'0';
            if(j>=0)sum+=s2[j--]-'0';
            result+=(sum%10)+'0';
            carry=sum/10;
        }
        reverse(result.begin(),result.end());
        // Remove leading zeros
        // Why while? Because there could be multiple leading zeroes, like "000123" → "123"
        // result.erase(0,1) removes 1 character at index 0.
        while(!result.empty()&&result[0]=='0')result.erase(0,1);

        if(result.empty())result="0";
        // After removing all leading zeros, if result becomes empty (like "000" becomes ""), you must set it to "0".
        // Why? Because an empty string is not a valid number — we return "0" instead.
        return result;
    }
    string minSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s1,s2;
        for(int i=0;i<n;i++){
            if(i%2==0)s1+=to_string(arr[i]);
            else s2+=to_string(arr[i]);
        }
        return addStrings(s1,s2);
    }
};

