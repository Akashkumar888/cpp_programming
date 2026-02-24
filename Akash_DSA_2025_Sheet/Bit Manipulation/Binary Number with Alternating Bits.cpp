class Solution {
public:
    bool hasAlternatingBits(int n) {
        int totalsBits=floor(log2(n))+1;
        cout<<totalsBits<<endl;
        for(int bit=0;bit<totalsBits-1;bit++){
         int currBit=(n>>bit)&1;
         int nextBit = (n >> (bit + 1)) & 1;
         if(currBit==nextBit)return false; 
        }
        return true;
    }
};

class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            int currBit = n & 1;
            int nextBit = (n >> 1) & 1;

            if (currBit == nextBit) return false;
            n = n >> 1;
        }
        return true;
    }
};



// ✅ 1️⃣ Count Total Bits Using Loop
// 🔹 Method 1: Right Shift Until Number Becomes 0
int countBits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n = n >> 1;   // remove last bit
    }
    return count;
}

// 🔹 Method 2: Using Left Shift (Less Common)
int countBits(int n) {
    int count = 0;
    while ((1 << count) <= n) {
        count++;
    }
    return count;
}

