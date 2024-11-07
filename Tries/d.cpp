
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    struct trieNode {
        trieNode* left;
        trieNode* right;
    };

    // Function to insert a number into the trie
    void insert(int& num, trieNode* root) {
        trieNode* temp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (temp->left == NULL) {
                    temp->left = new trieNode();
                }
                temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = new trieNode();
                }
                temp = temp->right;
            }
        }
    }

    // Function to find the maximum XOR of a number with the existing numbers in the trie
    int findxor(int& num, trieNode* root) {
        trieNode* temp = root;
        int max_xor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 0) {
                if (temp->right != NULL) {
                    max_xor += (1 << i);
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->left != NULL) {
                    max_xor += (1 << i);
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
        }
        return max_xor;
    }

    // Main function to find the maximum XOR of two numbers in the array
    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();
        for (int& num : nums) {
            insert(num, root);
        }

        int mxXor = 0;
        for (int i = 0; i < nums.size(); i++) {
            int mxval = findxor(nums[i], root);
            mxXor = max(mxXor, mxval);
        }
        return mxXor;
    }
};

int main() {
    // Create a solution object
    Solution solution;

    // Example input
    vector<int> nums = {3, 10, 5, 25, 2, 8};

    // Call the findMaximumXOR function and print the result
    int result = solution.findMaximumXOR(nums);
    cout << "The maximum XOR is: " << result << endl;

    return 0;
}
