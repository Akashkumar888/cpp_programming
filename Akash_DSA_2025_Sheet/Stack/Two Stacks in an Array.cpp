

class twoStacks {
public:
    int *arr;
    int size;
    int top1;
    int top2;

    twoStacks(int n = 100) {   // default size if not given
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // push into stack1
    void push1(int x) {
        if (top1 + 1 == top2) return; // overflow
        top1++;
        arr[top1] = x;
    }

    // push into stack2
    void push2(int x) {
        if (top2 - 1 == top1) return; // overflow
        top2--;
        arr[top2] = x;
    }

    // pop from stack1
    int pop1() {
        if (top1 == -1) return -1; // underflow
        return arr[top1--];
    }

    // pop from stack2
    int pop2() {
        if (top2 == size) return -1; // underflow
        return arr[top2++];
    }
};


class twoStacks {
  public:
//   1 ≤ number of queries ≤ 104
// 1 ≤ number of elements in the stack ≤ 100
// The sum of the count of elements in both the stacks < size of the given array
  vector<int>arr;
  int top1;
  int top2;
    twoStacks() {
        top1=-1;
        top2=100;
        arr.resize(100);
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top1+1==top2)return;
        top1++;
        arr[top1]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        if(top2-1==top1)return;
        top2--;
        arr[top2]=x;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(top1==-1)return -1;
        int val=arr[top1--];
        return val;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2==100)return -1;
        int val=arr[top2++];
        return val;
    }
};




class twoStacks {
  public:
  vector<int>st;
  int i,j,m;
    twoStacks() {
        m=100;
        st.resize(m);
        i=-1,j=m;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(i+1==j)return;
        i++;
        st[i]=x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        if(j-1==i)return;
        j--;
        st[j]=x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        // code here
        if(i==-1)return -1;
        int ele=st[i];
        i--;
        return ele;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(j==m)return -1;
        int ele=st[j];
        j++;
        return ele;
    }
};

// 🔹 Case 1
// twoStacks(int n = 100) {
//     cout << n << endl;
// }

// Calls:
// twoStacks();      // no argument
// twoStacks(10);    // one argument

// Output:
// 100
// 10

// Why?

// If no argument → default value 100 is used

// If argument given → default is ignored

// 🔹 Case 2
// twoStacks(int k, int n = 100) {
//     cout << k << " " << n << endl;
// }

// Calls:
// twoStacks(1, 2);
// twoStacks(10);

// Output:
// 1 2
// 10 100

// Why?

// twoStacks(1,2) → k=1, n=2

// twoStacks(10) → k=10, n takes default 100

// ✅ Rule: Default parameters must be from right to left

// 🔹 Case 3 ❌ (INVALID)
// twoStacks(int n = 100, int k) {
//     cout << k << " " << n << endl;
// }

// Calls:
// twoStacks(1,2);
// twoStacks(10);

// ❌ Compilation Error
// Why?

// Default arguments cannot appear before non-default

// C++ rule violation

// ❌ This is NOT allowed in C++

// 🔑 Golden Rules (Interview-ready)

// 1️⃣ Default arguments are applied only if argument is missing
// 2️⃣ Defaults must be given from right to left
// 3️⃣ You cannot skip a middle parameter
// 4️⃣ Function overloading ≠ default arguments

// 🎯 One-line interview answer

// Default arguments in C++ are used only when arguments are omitted and must be defined from rightmost parameters.