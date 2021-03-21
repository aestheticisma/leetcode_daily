// 使用两个标记变量

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return;
        int flagR = 0;
        int flagC = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i=0; i<rows; i++) 
            if (!matrix[i][0]) {
                flagC = 1;
                break;
            }
        for (int j=0; j<cols; j++)
            if (!matrix[0][j]) {
                flagR = 1;
                break;
            }
        for (int i=1; i<rows; i++)
            for (int j=1; j<cols; j++)
                if (!matrix[i][j])
                    matrix[0][j] = matrix[i][0] = 0;
        for (int i = 1; i<rows; i++)
            for (int j=1; j<cols; j++)
                if (!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
        if (flagR)
            for (int j=0; j<cols; j++)
                matrix[0][j] = 0;
        if (flagC)
            for (int i=0; i<rows; i++)
                matrix[i][0] = 0;
        return;
    }
};