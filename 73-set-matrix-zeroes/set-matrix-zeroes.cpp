class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<pair<int,int>> index;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                   index.push_back({i,j}); 
                }
            }
        }

        for(int i=0; i<index.size(); i++){
            // cout << index[i].first << " " << index[i].second << endl;
            int ithIndex = index[i].first;
            int jthIndex = index[i].second;

            // set that row as 0 
            for(int k=0; k<col; k++){
                matrix[ithIndex][k] = 0;
            }
            // set that col as 0
            for(int k=0; k<row; k++){
                matrix[k][jthIndex] = 0;
            }

        }


        

    }
};