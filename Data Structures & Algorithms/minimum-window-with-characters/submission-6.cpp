class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Frequency of characters required
        for (char ch : t) {
            need[ch]++;
        }

        int required = need.size(); // unique chars needed
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];

            // Expand window
            if (need.find(ch) != need.end()) {

                window[ch]++;

                // Character frequency satisfied
                if (window[ch] == need[ch]) {
                    formed++;
                }
            }

            // Try shrinking window
            while (formed == required) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];

                if (need.find(leftChar) != need.end()) {

                    window[leftChar]--;

                    // Window became invalid
                    if (window[leftChar] < need[leftChar]) {
                        formed--;
                    }
                }

                left++;
            }
        }

        return (minLen == INT_MAX)
            ? ""
            : s.substr(start, minLen);
    }
};