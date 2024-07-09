class Solution {
public:
    
    string removeDuplicates(string s) {
        char ch;
        stack <char> st;
        // string ans = "";

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
        
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};