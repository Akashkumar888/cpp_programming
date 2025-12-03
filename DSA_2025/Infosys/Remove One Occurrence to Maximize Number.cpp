
// 📌 Problem Description
// You are given:
// A string number representing a positive integer
// A character digit (0–9)
// Your task:

// 👉 Remove exactly ONE occurrence of the given digit from the number
// 👉 Such that the resulting number (in decimal) is maximized
// It is guaranteed that:
// The digit appears at least once in the number
// The number does not start with 0

// 🧠 Algorithm (Simple & Effective)
// Read the number as string n
// For each index i:
// If n[i] == digit, remove it creating a new string
// Convert the new string to integer
// Track the maximum among all such possible values
// Print the maximum at the end
// This works because:
// The string is short (<= 10⁵)
// Removing each occurrence and checking all possibilities is allowed and efficient

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    char d;
    cin >> s >> d;

    int ans = 0; // will store maximum number after removing one digit

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == d) {                     // remove this occurrence
            string str = s.substr(0, i) + s.substr(i + 1); 
            ans = max(ans, stoi(str));        // convert string → int and compare
        }
    }

    cout << ans;
    return 0;
}

// Remove Digit From Number to Maximize Result
// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string maxNumber;
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string str=number.substr(0,i) + number.substr(i+1);
                maxNumber=max(maxNumber,str);
            }
        }
        return maxNumber;
    }
};