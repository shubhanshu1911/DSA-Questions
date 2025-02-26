class Solution {
public:
    string checkPalindrome(string s, int left, int right){
        int maxi = INT_MIN;
        string longest;
        while(left>=0 && right <s.length() && s[left] == s[right]){
            int length = (right - left) +1;
            maxi = max(maxi,length);
            longest = s.substr(left,maxi);
            left --;
            right ++;
        }
        return longest;
    }
    string longestPalindrome(string s) {
        string ans;
        string currOddString;
        string currEvenString;
        for(int centre=0; centre<s.length(); centre++){
            // odd
            currOddString = checkPalindrome(s,centre,centre);
            if(ans.length() < currOddString.length()){
                ans = currOddString;
            }
            // even
            currEvenString = checkPalindrome(s,centre,centre+1);
            if(ans.length() < currEvenString.length()){
                ans = currEvenString;
            }
        }
        return ans;
    }
};