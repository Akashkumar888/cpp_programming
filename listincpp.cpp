
#include <iostream>
#include <list>
#include <algorithm> // For std::find

using namespace std;

int main() {
    // Create an empty list of integers
    list<int> ans;

    // Insertion at the beginning: O(1)
    ans.push_front(1); // Insert 1 at the beginning
    ans.push_front(2); // Insert 2 at the beginning

    // Insertion at the end: O(1)
    ans.push_back(3);  // Insert 3 at the end
    ans.push_back(4);  // Insert 4 at the end

    // Insertion at an arbitrary position: O(1) (with iterator)
    auto it = ans.begin();
    advance(it, 2); // Move iterator to the 3rd position
    ans.insert(it, 5);   // Insert 5 at the 3rd position

    // Traversal: O(n)
    cout << "List after insertion: ";
    for (int value : ans) {
        cout << value << " ";
    }
    cout << endl;

    // Searching for a specific value: O(n)
    it = find(ans.begin(), ans.end(), 3); // Search for the value 3
    if (it != ans.end()) {
        cout << "Value 3 found in the list." << endl;
    } else {
        cout << "Value 3 not found in the list." << endl;
    }

    // Deletion from the beginning: O(1)
    ans.pop_front(); // Remove the first element

    // Deletion from the end: O(1)
    ans.pop_back();  // Remove the last element

    // Deletion at an arbitrary position: O(1) (with iterator)
    it = ans.begin();
    advance(it, 1); // Move iterator to the 2nd position
    ans.erase(it);       // Erase the element at the 2nd position

    cout << "List after deletion: ";
    for (int value : ans) {
        cout << value << " ";
    }
    cout << endl;

    // Accessing element by index: O(n) (No direct access in list)
    it = ans.begin();
    advance(it, 1); // Move to 2nd element (0-based index)
    cout << "Element at index 1: " << *it << endl;

    // Size of the list: O(1)
    cout << "Size of the list: " << ans.size() << endl;

    return 0;
}
