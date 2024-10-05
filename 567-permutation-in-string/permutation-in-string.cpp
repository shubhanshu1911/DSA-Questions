class Solution {
public:
    // Helper function to compare two frequency arrays
    bool matches(int s1Freq[26], int windowFreq[26]) {
        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] != windowFreq[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, it is impossible for a permutation of s1 to be a substring of s2
        if (s1.size() > s2.size()) return false;

        // Frequency array for characters in s1
        int s1Freq[26] = {0};
        // Frequency array for the sliding window in s2
        int windowFreq[26] = {0};

        // Initialize the frequency array for s1
        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        // First window initialization: for the first 's1.size()' characters in s2
        for (int i = 0; i < s1.size(); i++) {
            windowFreq[s2[i] - 'a']++;
        }

        // Check if the first window is a permutation
        if (matches(s1Freq, windowFreq)) return true;

        // Slide the window over s2
        for (int i = s1.size(); i < s2.size(); i++) {
            // Add the new character in the window
            windowFreq[s2[i] - 'a']++;
            // Remove the character that is out of the window
            windowFreq[s2[i - s1.size()] - 'a']--;
            
            // Check if the current window is a permutation
            if (matches(s1Freq, windowFreq)) return true;
        }

        return false;
    }
    
    
};
