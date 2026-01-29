
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int n; // Capacity of the cache
    list<int> dll; // Doubly Linked List to maintain order of usage
    unordered_map<int, pair<list<int>::iterator, int>> mp; // Map to store key -> (iterator in dll, value)

public:
    // Constructor to initialize the cache with given capacity
    LRUCache(int cap) {
        n = cap;
    }

    // Mark a key as recently used
    void RecentlyUsed(int key) {
        dll.erase(mp[key].first); // Remove the key from its current position
        dll.push_front(key); // Insert it at the front of the list
        mp[key].first = dll.begin(); // Update the iterator in the map
    }

    // Get the value of a key if it exists
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1; // Key doesn't exist
        RecentlyUsed(key); // Mark key as recently used
        return mp[key].second; // Return the value
    }

    // Insert or update a key-value pair
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists, update its value and mark as recently used
            mp[key].second = value;
            RecentlyUsed(key);
        } else {
            // Key doesn't exist, insert it
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) { // Capacity exceeded, evict the least recently used key
            int key_tobe_del = dll.back(); // Key at the back of the list
            mp.erase(key_tobe_del); // Remove from map
            dll.pop_back(); // Remove from list
            n++;
        }
    }
};

// Example usage
int main() {
    LRUCache lru(2); // Create an LRU Cache with capacity 2
    lru.put(1, 10); // Insert key 1 with value 10
    lru.put(2, 20); // Insert key 2 with value 20
    cout << lru.get(1) << endl; // Output: 10 (key 1 is recently used)
    lru.put(3, 30); // Insert key 3, evicts key 2 (least recently used)
    cout << lru.get(2) << endl; // Output: -1 (key 2 is not in cache)
    lru.put(4, 40); // Insert key 4, evicts key 1
    cout << lru.get(1) << endl; // Output: -1 (key 1 is not in cache)
    cout << lru.get(3) << endl; // Output: 30
    cout << lru.get(4) << endl; // Output: 40
    return 0;
}
