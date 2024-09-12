class Solution {
public:
    string decodeString(string s) {
        stack <string> st;
        for(auto ch : s){
            if(ch == ']'){
                string stringToRepeat = "";
                // jo char h vo digit ke equal nhi h
                while(!st.empty() && st.top() != "["){
                    // string top = ;
                    stringToRepeat += st.top();// cancatinate all the char into the string
                    st.pop();
                }
                // extra pop krna padega
                st.pop();

                string numericTimes = "";
                // jo char h vo digit ke equal h
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);

                // final decoding
                string currentDecode = "";
                while(n--){
                    currentDecode += stringToRepeat;
                }
                st.push(currentDecode);

            }
            // ingore this '[' 
            else{
                string temp (1,ch); // string initialise with single char "ch"
                st.push(temp);
            }
        }

        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};