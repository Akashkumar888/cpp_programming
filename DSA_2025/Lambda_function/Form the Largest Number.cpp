
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<string>ans;
        for(int &num:arr)ans.push_back(to_string(num));
        auto lambda=[&](string s1,string s2){
          return s1+s2>s2+s1;// place s1 before s2 if s1+s2 is lexicographically larger
        };
        sort(ans.begin(),ans.end(),lambda);
        string result="";
        for(string &str:ans)result+=str;
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1); // erase first character
        }
        return result;
    }
};


// passing by reference with const & is safer and avoids unnecessary copies.
auto lambda = [&](const string &s1, const string &s2){
    return s1+s2 > s2+s1;
};

// The comparator is called like lambda(x, y) during sorting.
// x and y can be anywhere in the current portion of the array—the sort algorithm decides which elements to compare.
// The return value means:
// true → x should come before y in the final sorted array
// false → y should come before x
// Important: s1 is not necessarily “beginning of array” and s2 is not “end of array.” They are just two elements the sorting algorithm is comparing at that moment.
// In short for your example:
// Sort (lambda) → s1 and s2 are just two elements being compared; not necessarily beginning or end.
// Heap (cmp) → p1 and p2 are elements being compared internally by the heap; p1 is not necessarily bottom, p2 is not necessarily top. The heap ensures pq.top() is the element with highest priority according to your comparator.
