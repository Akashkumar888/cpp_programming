// 🔥 Key Insight
// odd = number of characters with odd frequency
// ✅ Minimum operations needed
// ✔ If you can REMOVE characters
// Minimum deletions = odd - 1
// ✔ If you can ADD characters
// Minimum insertions = odd - 1
// 🧠 Why?
// For palindrome:
// Only 1 odd allowed (middle character)
// So:
// If odd = 5
// You must fix 4 of them → make them even
// 👉 Each operation fixes 1 odd count
// s = "abc"
// freq: a=1, b=1, c=1 → odd = 3
// 👉 Need:
// 3 - 1 = 2 operations
  
// ✔ Remove 2 chars → "a"
// ✔ OR add 2 chars → "abcba"

// Example 2
// s = "aaabbb"
// freq: a=3, b=3 → odd = 2
// 👉 Need:
// 2 - 1 = 1 operation
// ✔ Remove 1 → "aaabb"
// ✔ OR add 1 → "aaabbb a"

// ✍️ Code (Return Minimum Changes)
int minChangesToMakePalindrome(string &s) {
    vector<int> freq(26, 0);
    
    for(char c : s) {
        freq[c - 'a']++;
    }
    
    int odd = 0;
    
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 != 0) odd++;
    }
    
    if(odd <= 1) return 0;
    
    return odd - 1;
}
