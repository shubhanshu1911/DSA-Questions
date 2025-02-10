#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // Stores last index of each character
        int left = 0, longest = 0;

        for (int right = 0; right < s.length(); right++) {
            // If character was seen before, move left past its last occurrence
            left = max(left, lastIndex[s[right]] + 1);
            
            // Store the last occurrence of the character
            lastIndex[s[right]] = right;
            
            // Update the longest length
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
