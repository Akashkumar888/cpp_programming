
class Solution {
public:
    int minVal(int a, int b) {
        return (a < b) ? a : b;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int solve(int fromCap, int toCap, int d) {
        int from = 0, to = 0;
        int steps = 0;

        while (from != d && to != d) {
            if (from == 0) {
                from = fromCap; // Fill
            } 
            else if (to == toCap) {
                to = 0; // Empty
            } 
            else {
                int pour = minVal(from, toCap - to);
                to += pour;
                from -= pour;
            }
            steps++;
        }
        return steps;
    }

    int minSteps(int m, int n, int d) {
        if (d > m && d > n) return -1;
        if (d % gcd(m, n) != 0) return -1;

        int ans1 = solve(m, n, d);
        int ans2 = solve(n, m, d);

        return (ans1 < ans2) ? ans1 : ans2;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Manual gcd (Euclidean algorithm)
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper min function
    int minVal(int a, int b) {
        return (a < b) ? a : b;
    }

    // Simulate pouring from one jug to another
    int pour(int fromCap, int toCap, int d) {
        int from = fromCap;  // fill from jug
        int to = 0;
        int step = 1;

        while (from != d && to != d) {
            // pour water
            int temp = minVal(from, toCap - to);
            to += temp;
            from -= temp;
            step++;

            if (from == d || to == d) break;

            // if from becomes empty → refill
            if (from == 0) {
                from = fromCap;
                step++;
            }

            // if to becomes full → empty it
            if (to == toCap) {
                to = 0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int m, int n, int d) {
        // Edge cases
        if (d == 0) return 0;
        if (d > m && d > n) return -1;

        // GCD feasibility check
        if (d % gcd(m, n) != 0) return -1;

        // Try both directions
        int ans1 = pour(m, n, d);
        int ans2 = pour(n, m, d);

        return (ans1 < ans2) ? ans1 : ans2;
    }
};
