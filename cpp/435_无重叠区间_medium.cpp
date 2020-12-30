class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int N = intervals.size();
        if(!N)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int end = intervals[0][1];
        int ans = 0;
        for(int i=1; i<N; i++){
            int start = intervals[i][0];
            if(start < end)
                ans++;
            else
                end = intervals[i][1];
        }
        return ans;
    }
};