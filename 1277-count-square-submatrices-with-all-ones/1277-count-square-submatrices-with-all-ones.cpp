class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        for(int i= 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != 1){
                    continue;
                }
                if(i > 0 && j > 0){
                    matrix[i][j] = matrix[i][j] + min(matrix[i-1][j-1] , min(matrix[i-1][j] , matrix[i][j-1]));
                }
                count = count + matrix[i][j];
            }
        }
        return count;
    }
};