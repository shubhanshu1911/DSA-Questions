class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            // opening bracket
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                // closing bracket - ch == )
                if(!st.empty()){
                    char openCh = st.top();
                    if(ch == ')' && openCh == '('){
                        // matching brackets
                        st.pop();
                    }
                    else if(ch == '}' && openCh == '{'){
                        // matching brackets
                        st.pop();
                    }
                    else if(ch == ']' && openCh == '['){
                        // matching brackets
                        st.pop();
                    }
                    else {
                        // bracklets not matching 
                        return false;
                    }
                }
                else{
                    // invalid string
                    return false;
                }
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