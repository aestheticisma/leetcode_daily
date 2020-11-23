class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v){
            return u[1]<v[1];
        });
        int ans = 1;
        int arrow_pos = points[0][1];
        for(const vector<int> &ballow:points)
            if(ballow[0] > arrow_pos){
                arrow_pos = ballow[1];
                ans++;
            }
        return ans;
    }
};