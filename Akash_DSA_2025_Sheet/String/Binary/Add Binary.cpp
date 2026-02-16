
class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size();
        int n=b.size();
        int i=m-1;
        int j=n-1;
        int carry=0;
        string result="";
        while(i>=0 && j>=0){
           int sum=(a[i]-'0') + (b[j]-'0') + carry;
           result.push_back((sum%2) + '0');// binary then %2
           carry=sum/2;
           i--;
           j--;
        }
        while(i>=0){
           int sum=(a[i]-'0')  + carry;
           result.push_back((sum%2) + '0');// binary then %2
           carry=sum/2;
           i--;
        }
        while(j>=0){
           int sum=(b[j]-'0') + carry;
           result.push_back((sum%2) + '0');// binary then %2
           carry=sum/2;
           j--;
        }
        if(carry)result.push_back((carry%2) +'0');// binary then %2
        reverse(result.begin(),result.end());
        return result;
    }
};
// 🔥 Summary of Conversions
// 🔹 int → char
// char c = num + '0';

// 🔹 char → int (digit)
// int num = c - '0';
// Example:
// '7' - '0' = 55 - 48 = 7

// 🔥 char → string
// string s(1, c);
// OR
// string s = "";
// s += c;

// 🔥 int → string
// string s = to_string(num);

// 🔥 string → int
// int num = stoi(s);

// 🎯 Final Answer
// result.push_back(sum % 2 + '0');


class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};



class Solution {
public:
    string addBinary(string s1, string s2) {
        string ans="";
        int n1=s1.size();
        int n2=s2.size();
        int carry=0;
        int one=0;
        int i=n1-1,j=n2-1;
        while(i>=0 || j>=0){
            if(i>=0 && s1[i]=='1')one++;
            if(j>=0 && s2[j]=='1')one++;
            if(one+carry==0){
                ans='0'+ans;
                carry=0;
            }
            else if(one+carry==1){
                ans='1'+ans;
                carry=0;
            }
            else if(one+carry==2){
                ans='0'+ans;
                carry=1;
            }
            else if(one+carry==3){
                ans='1'+ans;
                carry=1;
            }
            one=0;
            i--,j--;
        }
        if(carry==1)ans='1' + ans;
        return ans;
    }
};


class Solution {
public:
    string addBinary(string s1, string s2) {
        string ans="";
        int n1=s1.size();
        int n2=s2.size();
        int carry=0;
        int one=0;
        int i=n1-1,j=n2-1;
        while(i>=0 || j>=0){
            if(i>=0 && s1[i]=='1')one++;
            if(j>=0 && s2[j]=='1')one++;
            if(one+carry==0){
                ans=ans+'0';
                carry=0;
            }
            else if(one+carry==1){
                ans=ans+'1';
                carry=0;
            }
            else if(one+carry==2){
                ans=ans+'0';
                carry=1;
            }
            else if(one+carry==3){
                ans=ans+'1';
                carry=1;
            }
            one=0;
            i--,j--;
        }
        if(carry==1)ans=ans +'1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


// 🧠 Golden Pattern (VERY IMPORTANT)
// Whenever doing addition:

// while(x || y || carry){
//     sum = carry
//     if(x) sum += x
//     if(y) sum += y

//     result = sum % base
//     carry = sum / base
// }

// This works for:
// Binary strings
// Decimal strings
// Linked lists
// Large number problems
// Base conversion problems
// 🎯 Final Answer
// YES ✅
// Always use the second version (single while loop).
// It is:
// Cleanest
// Most reusable
// Most scalable
// Most interview-friendly
// Works for linked list problems