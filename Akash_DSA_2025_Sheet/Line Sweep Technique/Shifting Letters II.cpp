
result[i] = 'a' + (s[i] - 'a' + 1) % 26;// forward
result[i] = 'a' + (s[i] - 'a' - 1 + 26) % 26;// backward




class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        // line sweep difference array
        for (auto &shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            int val = (direction == 1) ? 1 : -1;
            diff[start] += val;
            diff[end + 1] -= val;
        }

        string result = s;
        int curShift = 0;

        for (int i = 0; i < n; i++) {
            curShift += diff[i];
            int shift = ((curShift % 26) + 26) % 26; // normalize

            result[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return result;
    }
};




class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        // line sweep difference array
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            int val = (direction == 1) ? 1 : -1;
            diff[start] += val;
            diff[end + 1] -= val;
        }

        string result = s;
        int curShift = 0;

        for (int i = 0; i < n; i++) {
            curShift += diff[i];
            int shift = ((curShift % 26) + 26) % 26; // normalize

            if (shift > 0) result[i] = 'a' + (s[i] - 'a' + shift) % 26; // forward
            else if (shift < 0) result[i] = 'a' + (s[i] - 'a' - shift + 26) % 26; // backward
        }

        return result;
    }
};




// That said: map is logically clean but slower (O(q log q + n log q)), while the array version is optimal. Still, here’s the correct map-based sweep in your style.
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        map<int, int> events;

        // build sweep events
        for (auto &shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            int val = (direction == 1) ? 1 : -1;
            events[start] += val;
            events[end + 1] -= val;
        }

        string result = s;
        int curShift = 0;
        auto it = events.begin();

        // sweep through string indices
        for (int i = 0; i < n; i++) {
            // apply all events at index i
            while (it != events.end() && it->first == i) {
                curShift += it->second;
                it++;
            }

            int shift = ((curShift % 26) + 26) % 26;
            result[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return result;
    }
};

