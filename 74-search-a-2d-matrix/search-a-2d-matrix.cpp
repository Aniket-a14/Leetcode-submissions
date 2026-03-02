class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_l = 0;
        int row_h = matrix.size()-1;

        int row = 0;

        while(row_l<=row_h){
            int mid = row_l + (row_h-row_l)/2;
            if(matrix[mid][0]>target){
                row_h = mid - 1;
            }else{
                row = mid;
                row_l = mid + 1;
            }
        }

        int col_l = 0, col_h = matrix[0].size()-1;

        while(col_l<=col_h){
            int mid = col_l + (col_h-col_l)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target){
                col_h = mid - 1;
            }else{
                col_l = mid + 1;
            }
        }

        return false;
    }
};
