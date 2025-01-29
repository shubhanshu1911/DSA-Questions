class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Take transpose of a matrix
        for(int i=0; i<n; i++){
            for(int j=i; j<m; j++){
                if(i!=j){
                    swap(matrix[i][j], matrix[j][i]);
                }
                else{
                    continue;
                }
            }
        }

        // Reverse 1st and the last column
        for(int i=0; i<n; i++){
            int x = 0; 
            int y = matrix[0].size()-1;

            while(x<=y){
                swap(matrix[i][x],matrix[i][y]);
                x++;
                y--;
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<< matrix [i][j] << " ";
        //     }
        //     cout<< endl;
        // }
    }
};