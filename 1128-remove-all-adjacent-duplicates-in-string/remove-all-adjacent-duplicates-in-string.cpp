class Solution {
public:
    string removeDuplicates(string s) {
       string ans = "";
       int i =0;
       while(i < s.length()){
            // string is not empty 
           if(ans.length() > 0){
               if(ans[ans.length()-1] == s[i]){
                   ans.pop_back();
               }
               else{
                   ans.push_back(s[i]);
               }
           }
            // string is empty
           else{
               ans.push_back(s[i]);
           }
           i++;
       }
       return ans; 
    }
};