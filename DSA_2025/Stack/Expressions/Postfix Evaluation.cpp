
// Postfix Expression (Reverse Polish Notation)
// Operator comes after operands.
// Example: A B +
// Evaluated left to right using a stack.
// No parentheses needed.
// ✅ Your problem is about evaluating a postfix expression.


class Solution {
  public:
  int arithmetic(string &ch,int val1,int val2){
      if(ch=="+")return val1+val2;
      else if(ch=="-")return val1-val2;
      else if(ch=="*")return val1*val2;
      return val1/val2;
  }
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(string &ch:arr){
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                int val=arithmetic(ch,val2,val1);
                st.push(val);
            }
            else st.push(stoi(ch));
        }
    return st.top();
    }
};

// And the division operation between two integers always computes the floor value.
class Solution {
  public:
  double func(int num1,int num2,string &opr){
      if(opr=="+")return num1+num2;
      else if(opr=="-")return num1-num2;
      else if(opr=="*")return num1*num2;
      else if(opr=="/") return floor(double(num1) / double(num2)); // floor here
      else return pow(num1,num2);
  }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        // And the division operation between two integers always computes the floor value.
        stack<double>numbers;
        for(string &str:arr){
            if(str=="+" ||str=="-"||str=="*"||str=="/"||str=="^"){
                double num2=numbers.top();
                numbers.pop();
                double num1=numbers.top();
                numbers.pop();
                double value=func(num1,num2,str);
                numbers.push(value);
            }
            else numbers.push(stoi(str));
        }
        return floor(numbers.top());
    }
};



// 1️⃣ Time Complexity
// Step-by-step:
// You iterate over all elements in the arr vector of size n.
// This is O(n).
// For each operator (+, -, *, /, ^), you:
// Pop two elements from the stack → O(1)
// Perform the operation → O(1)
// Push the result back → O(1)
// For each operand, you just push onto the stack → O(1)
// ✅ So for n elements, the total time complexity is: O(n)

// 2️⃣ Space Complexity
// You use a stack to store numbers.
// In the worst case, if all n elements are numbers (no operators yet), the stack will hold all n elements.
// So stack space → O(n)
// Other variables like num1, num2, value → O(1)
// ✅ So the total space complexity is:O(n)
