
// Step 1: Ask "What is the current state?"
// For this problem:
// level = 4
// pos = 2
// Current state is:
// (level,pos)
// So recursive function should depend on:
// solve(level,pos)

// Step 2: Find the smallest problem (Base Case)
// Tree starts with:
// Level 1
// Engineer
// Therefore:
// if(level==1)
//     return Engineer;

// Step 3: How is current answer related to smaller answer?
// This is the MOST IMPORTANT STEP.
// Suppose:
// Parent = Engineer
// Children:
// 1st -> Engineer
// 2nd -> Doctor
// Suppose:
// Parent = Doctor
// Children:
// 1st -> Doctor
// 2nd -> Engineer
// Observe:
// 1st child = same as parent
// 2nd child = opposite of parent
// This is the whole recursion.

// Step 4: Move to parent
// At level:
// level = 4
// pos = 5
// Who is parent?
// Level 4:
// 1 2 3 4 5 6 7 8
// Parent positions:
// 1,2 -> parent 1
// 3,4 -> parent 2
// 5,6 -> parent 3
// 7,8 -> parent 4
// Formula:
// parentPos=(pos+1)/2;

// Step 5: Solve parent first
// parent=solve(level-1,parentPos);

// Step 6: Determine current node

// Odd position
// 1st child
// Same as parent.
// if(pos%2==1)
//     return parent;

// Even position
// 2nd child
// Opposite of parent.
// if(parent=="Engineer")
//     return "Doctor";
// else
//     return "Engineer";


class Solution {
  public:

    string solve(int level,int pos){

        if(level==1){
            return "Engineer";
        }

        string parent=solve(level-1,(pos+1)/2);

        if(pos%2==1){
            return parent;
        }

        return (parent=="Engineer") ? "Doctor" : "Engineer";
    }

    string profession(int level, int pos) {
        return solve(level,pos);
    }
};



class Solution {
  public:

    string solve(int pos){

        if(pos==1){
            return "Engineer";
        }

        string parent = solve((pos+1)/2);

        if(pos%2==1){
            return parent;
        }

        return (parent=="Engineer") ? "Doctor" : "Engineer";
    }

    string profession(int level, int pos) {
        return solve(pos);
    }
};



class Solution {
  public:
    string profession(int level, int pos) {

        int setBits = __builtin_popcount(pos-1);

        if(setBits % 2 == 0){
            return "Engineer";
        }

        return "Doctor";
    }
};


