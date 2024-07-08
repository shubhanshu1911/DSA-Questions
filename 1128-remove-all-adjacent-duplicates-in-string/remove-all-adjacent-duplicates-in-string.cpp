class Solution {
public:
    
    string removeDuplicates(string s) {
        char ch;
        stack <char> st;
        string ans = "";

        for(int i=0; i<s.length(); i++){
            ch = s[i];
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(ch == st.top()){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};