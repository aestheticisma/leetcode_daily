class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int mid = 0;
        int top = 0;
        int bottom = row;
        while (top < bottom) {
            mid = (top+bottom) / 2;
            if (target == matrix[mid][0])
                return true;
            else if (target < matrix[mid][0])
                bottom--;
            else {
                if (target == matrix[mid][col-1])
                    return true;
                else if (target < matrix[mid][col-1])
                    return findx(matrix[mid], target);
                else
                    top++;
            }
        }
        return false;
    }
    bool findx(vector<int> &matrix_rows, int target) {
        for (auto num : matrix_rows) {
            if (target == num)
                return true;
        }
        return false;
    }
};