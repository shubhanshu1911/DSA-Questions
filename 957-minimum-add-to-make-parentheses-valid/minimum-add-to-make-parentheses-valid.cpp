class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_needed = 0; // Counter for unmatched '('
        int close_needed = 0; // Counter for unmatched ')'
        
        for (char ch : s) {
            if (ch == '(') {
                // Increment the open needed counter for every '('
                open_needed++;
            } else if (ch == ')') {
                // If we have unmatched '(', we can match it with this ')'
                if (open_needed > 0) {
                    open_needed--;
                } else {
                    // Otherwise, we need an extra '(' for this unmatched ')'
                    close_needed++;
                }
            }
        }
        
        // The total moves needed is the sum of unmatched '(' and unmatched ')'
        return open_needed + close_needed;
    }
};
