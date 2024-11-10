#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to update the bit frequency in 'mp'
void update(int num, vector<int> &mp, int val)
{
  for (int i = 31; i >= 0; i--)
  {
    if (num & (1 << i))
    {
      mp[i] += val;
    }
  }
}

// Function to calculate the number represented by the current bit frequencies
int numbers(vector<int> &mp)
{
  int num = 0;
  for (int i = 31; i >= 0; i--)
  {
    if (mp[i] > 0)
    {
      num |= (1 << i);
    }
  }
  return num;
}

// Function to find the minimum subarray length with bitwise OR >= k
int minimumSubarrayLength(vector<int> &nums, int k)
{
  vector<int> mp(32, 0); // To track the count of set bits at each position
  int minsize = INT_MAX;
  int n = nums.size();
  int i = 0, j = 0;

  while (j < n)
  {
    // Expand the window by adding nums[j]
    update(nums[j], mp, 1);

    // Shrink the window from the left as long as the bitwise OR is >= k
    while (i <= j && numbers(mp) >= k)
    {
      minsize = min(minsize, j - i + 1);
      update(nums[i], mp, -1);
      i++;
    }
    j++;
  }

  return minsize == INT_MAX ? -1 : minsize;
}

int main()
{
  // Example 1: nums = [1, 2, 3], k = 2
  vector<int> nums1 = {1, 2, 3};
  int k1 = 2;
  cout << "Minimum subarray length (nums = {1, 2, 3}, k = 2): "
       << minimumSubarrayLength(nums1, k1) << endl;

  // Example 2: nums = [2, 1, 8], k = 10
  vector<int> nums2 = {2, 1, 8};
  int k2 = 10;
  cout << "Minimum subarray length (nums = {2, 1, 8}, k = 10): "
       << minimumSubarrayLength(nums2, k2) << endl;

  // Example 3: nums = [1, 2], k = 0
  vector<int> nums3 = {1, 2};
  int k3 = 0;
  cout << "Minimum subarray length (nums = {1, 2}, k = 0): "
       << minimumSubarrayLength(nums3, k3) << endl;

  return 0;
}
