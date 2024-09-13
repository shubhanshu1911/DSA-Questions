class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n); // Pair of position and time to target

        // Create a pair of {position, time to reach target}
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }

        // Sort cars by position in descending order (closer to target first)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0.0;

        // Traverse from the car closest to the target to the farthest
        for (int i = 0; i < n; ++i) {
            // If the current car takes more time than the last car's fleet, it forms a new fleet
            if (cars[i].second > lastTime) {
                fleets++;
                lastTime = cars[i].second; // Update the last fleet's time
            }
        }

        return fleets;
    }
};
