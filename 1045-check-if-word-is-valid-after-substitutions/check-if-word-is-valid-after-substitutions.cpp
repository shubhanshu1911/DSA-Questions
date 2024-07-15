class Solution {
public:
    bool isValid(string s) {
        char ch;
        stack <char> st;

        for(int i=0; i<s.length(); i++){
            ch = s[i];
            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b'){
                st.push(ch);
            }
            else if(ch == 'c' && !st.empty() && st.top() == 'b' ){
                st.pop();
                if(!st.empty() && st.top() == 'a' ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else {
                return false;
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};      