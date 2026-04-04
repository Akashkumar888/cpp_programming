
class Solution {
  public:
//A Gray code sequence must begin with 0.
// gray code cyclic code
// gray code is unit distance code
// » Also known as Reflected Binary Code. ( R B C)
// »> We call it Gray Code after Frank Gray.
// » Unweighted code.
// » Unit distance code & Minimum error code.
// Binary to Gray Code Conversion (imp )
// Step 1: Record the MSB as it is.
// Step 2: Add the MSB to the next bit, record the sum and neglect the carry.
// Step 3: Repeat the process.
    void solve(int n, vector<string>& result){
        // base case
        if(n == 1){
            result.push_back("0");
            result.push_back("1");
            return;
        }
        // get (n-1) gray code
        solve(n-1,result);
        int size=result.size();
        // add '0' to existing
        for(int i = 0; i < size; i++){
            result[i] = "0" + result[i];
        }
        // add '1' to reversed
        for(int i = size-1; i >= 0; i--){
            result.push_back("1" + result[i].substr(1));
        }
    }
    vector<string> graycode(int n) {
        vector<string> result;
        solve(n, result);
        return result;
    }
};



class Solution {
  public:
//A Gray code sequence must begin with 0.
// gray code cyclic code
// gray code is unit distance code
// » Also known as Reflected Binary Code. ( R B C)
// »> We call it Gray Code after Frank Gray.
// » Unweighted code.
// » Unit distance code & Minimum error code.
// Binary to Gray Code Conversion (imp )
// Step 1: Record the MSB as it is.
// Step 2: Add the MSB to the next bit, record the sum and neglect the carry.
// Step 3: Repeat the process.
    vector<string> graycode(int n) {
        if(n == 1) return {"0", "1"};
        vector<string> prev = graycode(n-1);
        vector<string> result;
        // add 0 prefix
        for(auto &s : prev){
            result.push_back("0" + s);
        }
        // add 1 prefix (reverse order)
        for(int i = prev.size()-1; i >= 0; i--){
            result.push_back("1" + prev[i]);
        }
        return result;
    }
};