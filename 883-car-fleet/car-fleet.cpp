class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n); // Pair of position and time to target
        // int fleet;
        stack<double> st;

        // Create a pair of {position, time to reach target}
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        // Sort cars by position in increasing order (closer to target first)
        sort(cars.begin(), cars.end());

        for(int j=0; j<cars.size(); j++){
            // cout << cars[j].first << "," << cars[j].second << " ";
            double currTime = cars[j].second;
            // Insert into stack
            while(!st.empty() && currTime >= st.top()){
                st.pop();
            }
            st.push(currTime);
        }

        return st.size();
    }
};
