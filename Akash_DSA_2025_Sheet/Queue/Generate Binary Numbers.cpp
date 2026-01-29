
class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
       // queue
        //   ↔ Rear      [ A ] [ B ] [ C ] [ D ]    Front ↔
        //   push/queue↑                            ↑queue/pop
        if(n==1)return {"1"};
        vector<string>ans;
        queue<string>q;
        q.push("1");
        ans.push_back("1");
        int len=n/2;
        while(!q.empty() && len--){
            string str=q.front();
            q.push(str+"0");
            ans.push_back(str+"0");
            q.push(str+"1");
            ans.push_back(str+"1");
            q.pop();
        }
        if(n%2==0)ans.pop_back();
        return ans;
    }
};



class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string>ans;
        queue<string>q;
        q.push("1");
        while(!q.empty() && n--){
            string str=q.front();
            q.pop();
            ans.push_back(str);
            q.push(str+"0");
            q.push(str+"1");
        }
        return ans;
    }
};