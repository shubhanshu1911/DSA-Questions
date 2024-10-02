class Solution {
public:
    // Function to check if the rhombus vertices are within bounds
    bool checkBounds(vector<vector<int>>& grid, vector<pair<int, int>>& v) {
        int m = grid.size();
        int n = grid[0].size();
        for (auto pt : v) {
            if (pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n) {
                return false;
            }
        }
        return true;
    }

    // Function to get all the vertices of the rhombus
    bool getAllVertices(vector<vector<int>>& grid, vector<pair<int, int>>& v, pair<int, int> c, int& delta) {
        pair<int, int> A(c.first - delta, c.second);    // Top vertex
        pair<int, int> B(c.first, c.second + delta);    // Right vertex
        pair<int, int> C(c.first + delta, c.second);    // Bottom vertex
        pair<int, int> D(c.first, c.second - delta);    // Left vertex
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        return checkBounds(grid, v);
    }

    // Function to calculate the sum for all possible rhombuses centered at (cx, cy)
    void getAllSum(vector<vector<int>>& grid, int& cx, int& cy, set<int>& sums) {
        // Push Rhombus sum of Rhombus with area 0 (just the center point)
        sums.insert(grid[cx][cy]);

        int delta = 1;
        vector<pair<int, int>> v(4);

        // Keep increasing delta until the rhombus vertices go out of bounds
        while (getAllVertices(grid, v, {cx, cy}, delta)) {
            pair<int, int>& A = v[0];
            pair<int, int>& B = v[1];
            pair<int, int>& C = v[2];
            pair<int, int>& D = v[3];

            // Sum up the values at the vertices
            int currSum = grid[A.first][A.second] + grid[B.first][B.second] +
                          grid[C.first][C.second] + grid[D.first][D.second];

            // Sum the cells along the edges of the rhombus
            for (int i = 1; i < delta; i++) {
                // A -> B (Top-Right Diagonal)
                currSum += grid[A.first + i][A.second + i];
                // B -> C (Bottom-Right Diagonal)
                currSum += grid[B.first + i][B.second - i];
                // C -> D (Bottom-Left Diagonal)
                currSum += grid[C.first - i][C.second - i];
                // D -> A (Top-Left Diagonal)
                currSum += grid[D.first - i][D.second + i];
            }

            // Insert the calculated sum into the set
            sums.insert(currSum);
            ++delta;
        }
    }

    // Main function to get the largest three distinct rhombus sums
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> sums;
        int m = grid.size();
        int n = grid[0].size();

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                getAllSum(grid, i, j, sums);
            }
        }

        // Extract the largest three distinct sums from the set
        vector<int> ans;
        vector<int> sortedSums(sums.begin(), sums.end());  // Copy the set into a vector

        // Use a normal for loop to get the last 3 elements (largest ones)
        for (int i = sortedSums.size() - 1; i >= 0 && ans.size() < 3; i--) {
            ans.push_back(sortedSums[i]);
        }

        return ans;
    }
};
