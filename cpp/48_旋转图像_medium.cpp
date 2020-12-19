class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        auto tmp = matrix;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                matrix[j][N-i-1] = tmp[i][j];
    }
};