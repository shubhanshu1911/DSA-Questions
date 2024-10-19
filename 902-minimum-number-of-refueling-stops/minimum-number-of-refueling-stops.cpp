class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;  // Max-heap to store fuel from stations we've passed
        int currFuel = startFuel;
        int stops = 0, i = 0;  // `stops` counts the refuelings, `i` is for stations index
        
        while (currFuel < target) {  // While we can't reach the target
            // Add all stations we can reach with the current fuel to the heap
            while (i < stations.size() && stations[i][0] <= currFuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            
            // If there are no stations left in heap to refuel and we can't reach target
            if (maxHeap.empty()) return -1;
            
            // Refuel with the largest fuel station we've passed
            currFuel += maxHeap.top();
            maxHeap.pop();
            stops++;  // One more refueling stop
        }
        
        return stops;
    }
};