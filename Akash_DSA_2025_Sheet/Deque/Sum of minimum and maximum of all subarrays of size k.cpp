
// 3️⃣ Condition variants
// dq.front() <= i-k
// // vs
// i - dq.front() >= k

// ✔ Both are 100% equivalent
// ✔ Both correctly remove out-of-window indices


long long sumOfMinMax(vector<int>& nums, int k) {
    deque<int> minDq, maxDq;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {

        // Remove elements outside the window
        if (!minDq.empty() && minDq.front() <= i - k)
            minDq.pop_front();
        if (!maxDq.empty() && maxDq.front() <= i - k)
            maxDq.pop_front();

        // Maintain increasing order for min deque
        while (!minDq.empty() && nums[minDq.back()] >= nums[i])
            minDq.pop_back();

        // Maintain decreasing order for max deque
        while (!maxDq.empty() && nums[maxDq.back()] <= nums[i])
            maxDq.pop_back();

        minDq.push_back(i);
        maxDq.push_back(i);

        // Add result when window is ready
        if (i >= k - 1)
            sum += nums[minDq.front()] + nums[maxDq.front()];
    }
    return sum;
}



long long sumOfMinMax(vector<int>& nums, int k) {
    deque<int> minDq, maxDq;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++) {

        // Remove elements outside the window
        while (!minDq.empty() && i - minDq.front() >=  k)
            minDq.pop_front();
        while (!maxDq.empty() && i - maxDq.front() >= k)
            maxDq.pop_front();

        // Maintain increasing order for min deque
        while (!minDq.empty() && nums[minDq.back()] >= nums[i])
            minDq.pop_back();

        // Maintain decreasing order for max deque
        while (!maxDq.empty() && nums[maxDq.back()] <= nums[i])
            maxDq.pop_back();

        minDq.push_back(i);
        maxDq.push_back(i);

        // Add result when window is ready
        if (i - k + 1 >= 0)
            sum += nums[minDq.front()] + nums[maxDq.front()];
    }
    return sum;
}

// ✅ Approach 2: Multiset (Balanced BST)
// Time: O(n log k) | Space: O(k)
// 👉 Easy to understand, slower than deque

// Idea
// Maintain current window elements in a multiset
// First element → minimum
// Last element → maximum


// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[], int n, int k)
{
    int sum = 0; // to store our final sum
    // multiset because nos. could be repeated
    // multiset pair is {number,index}
    multiset<pair<int, int> > ms;
    int i = 0; // back pointer
    int j = 0; // front pointer
    while (j < n && i < n) {
        ms.insert(
            { arr[j], j }); // inserting {number,index}

        // front pointer - back pointer + 1 is for checking
        // window size
        int windowSize = j - i + 1;

        // Once they become equal, start what we need to do
        if (windowSize == k) {

            // extracting first since set is always in
            // sorted ascending order
            int mini = ms.begin()->first;

            // extracting last element aka beginning from
            // last (numbers extraction)
            int maxi = ms.rbegin()->first;

            // adding summation of maximum & minimum element
            // of each subarray of k into final sum
            sum += (maxi + mini);

            // erasing the ith index element from set as it
            // won't appaer in next window of size k
            ms.erase({ arr[i], i });

            // increasing back pointer for next window of
            // size k;
            i++;
        }
        j++; // always increments front pointer
    }
    return sum;
}




// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum = 0;  // Initialize result

    // The queue will store indexes of useful elements
    // in every window
    // In deque 'G' we maintain decreasing order of
    // values from front to rear
    // In deque 'S' we  maintain increasing order of
    // values from front to rear
    deque< int > S(k), G(k);

    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Process rest of the Array elements
    for (  ; i < n; i++ )
    {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];

        // Remove all elements which are out of this
        // window
        if ( !S.empty() && S.front() == i - k)
            S.pop_front();
        if ( !G.empty() && G.front() == i - k)
            G.pop_front();

        // remove all previous greater element that are
        // useless
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];

    return sum;
}

// Driver program to test above functions