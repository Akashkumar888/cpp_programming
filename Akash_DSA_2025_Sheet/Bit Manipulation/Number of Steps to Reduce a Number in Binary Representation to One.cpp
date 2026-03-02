
// in binary if LSB 1 then odd numbers
// if 0 then even numbers 

// ✅ Theory: What Happens When We Add 1 to an Odd Binary Number?
// If a binary number is odd, its last bit is always:
// ...1
// When we add 1:

// 🔁 Rule (Right → Left Processing)
// Start from the rightmost bit
// If bit = 1
// It becomes 0
// Carry moves to next left bit
// Continue converting 1 → 0
// When first 0 is found:
// Convert it to 1
// Stop carry
// If no 0 is found:
// All bits become 0
// Add new leading 1

// 🔥 Why Does Odd + 1 Become Even?
// Odd number → last bit = 1
// After adding 1:
// ...1 + 1 → ...0 (carry)
// So last bit becomes 0 → number becomes even.

// 📘 Example 1
// Add 1 to:
// 1011   (11 in decimal)
// Step-by-step:
//    1011
// +     1
// --------
//    1100

// Explanation:
// Rightmost 1 → 0 (carry)
// Next 1 → 0 (carry)
// Next 0 → 1 (carry stops)
// Final result:
// 1100 (12 in decimal)


int binaryToDecimal(string &s){
    int decimal=0;
    for(int i=0;i<s.size();i++){
    decimal=(decimal<<1) + (s[i]-'0'); // when left to right traverse
    }
    return decimal;
}


// 🔁 If You Traverse Right → Left
// Then you must multiply by powers of 2 manually.
// ✅ Method 1: Using Power Variable (Best Way)

int binaryToDecimal(string &s){
    int decimal = 0;
    int power = 1;   // 2^0

    for(int i = s.size()-1; i >= 0; i--){
        decimal += (s[i]-'0') * power;
        power *= 2;
    }

    return decimal;
}

// ⚡ Alternative (Using Bit Shift Instead of Power)
int binaryToDecimal(string &s){
    int decimal = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[s.size()-1-i] == '1')
            decimal += (1 << i);
    }

    return decimal;
}


// 🧠 Mathematical Understanding
// When num is:
// Even → one step (divide by 2)
// Odd → two steps
// num++ → becomes even
// /2 in next iteration
// So for every 1 bit in binary:
// It causes 1 increment step
// And eventually a division step

// 🔥 Key Insight (Binary View)
// Let:
// b = number of bits in num
// ones = number of set bits (1s)

// Total steps:
// Steps=(b−1)+ones
// ✅ Why?

// Every bit needs one divide step → (b - 1)
// Every 1 needs one extra increment step → ones

// 🚀 Final Mathematical Code (O(log n))

long long steps(long long num){
    if(num==0) return 0;

    long long bits = floor(log2(num)) + 1;
    long long ones = __builtin_popcountll(num);

    return (bits - 1) + ones;
}




// 🔥 Optimized String Solution (O(n))
class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        for(int i = s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if(bit % 2 == 0) {
                steps += 1;      // divide by 2
            } else {
                steps += 2;      // +1 then divide
                carry = 1;
            }
        }

        return steps + carry;
    }
};