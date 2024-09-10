class Solution {
public:
    void insertSorted(stack< pair<string,int> > &s, pair<string,int> target){
        // base case 
        if(s.empty()){
            s.push(target);
            return;
        }
        if(s.top().second >= target.second){
            s.push(target);
            return;
        }

        // 1 case 
        pair<string,int> topElement = s.top();
        s.pop();
        // rec call
        insertSorted(s, target);
        // BT
        s.push(topElement);
    }

    void sortStack(stack< pair<string,int> > &s){
        // base case 
        if(s.empty()){
            return;
        }

        pair<string,int> topElement = s.top();
        s.pop();

        sortStack(s);

        insertSorted(s, topElement);
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        stack< pair<string,int> > s;

        for(int i=0; i<heights.size(); i++){
            s.push(make_pair(names[i], heights[i]));
        }

        sortStack(s);

        while(!s.empty()){
            string currElement = s.top().first;
            s.pop();
            ans.push_back(currElement);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};