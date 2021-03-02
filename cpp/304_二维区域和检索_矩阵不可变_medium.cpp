class NumMatrix {
public:
    vector<int> mm;
    int row = 0;
    int col = 0;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size()==0) return;
        mm.push_back(0);
        row = matrix.size();
        col = matrix[0].size();
        for (int i=0; i<row; i++)
            for (int j=0; j<col; j++){
                if (i==0)
                    mm.push_back(matrix[i][j]+mm.back());
                else{
                    if (j==0)
                        // mm.push_back(matrix[i][j]+mm[(i-1)*col+j+1]);
                        mm.push_back(matrix[i][j] + mm[get(i-1,j)]);
                    else
                        // mm.push_back(matrix[i][j]+mm[(i-1)*col+j+1]+mm[i*col+j]-mm[(i-1)*col+j]);
                        mm.push_back(matrix[i][j] + mm[get(i-1,j)] + mm[get(i,j-1)] - mm[get(i-1,j-1)]);
                }
            }
    }
    int get(int i, int j){
        return i*col+j+1;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        if (row1==0 && col1>0) ans = mm[get(row2,col2)] - mm[get(row2,col1-1)];
        else if (row1>0 && col1==0) ans = mm[get(row2,col2)] - mm[get(row1-1, col2)];
        else if (row1==0 && col1==0) ans = mm[get(row2,col2)];
        else ans = mm[get(row2,col2)] - mm[get(row2,col1-1)] - mm[get(row1-1, col2)] + mm[get(row1-1,col1-1)];
        // return mm[get(row2,col2)] - mm[get(row2,col1-1)] - mm[get(row1-1, col2)] + mm[get(row1-1,col1-1)];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */