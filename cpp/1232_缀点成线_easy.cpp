class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int N = coordinates.size();
        if(N<3)
            return true;
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        for(int i=1; i<N; i++){
            coordinates[i][0]-=x0;
            coordinates[i][1]-=y0;
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for(int i=2; i<N; i++)
            if(A*coordinates[i][0]+B*coordinates[i][1]!=0)
                return false;
        return true;
    }
};