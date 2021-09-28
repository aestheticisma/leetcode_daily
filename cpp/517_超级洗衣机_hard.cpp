class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int all = accumulate(machines.begin(), machines.end(), 0);
        if (all % n) return -1;
        int avg = all / n;
        int ans = 0, sub = 0;
        for (auto num : machines) {
            num -= avg;
            sub += num;
            ans = max(ans, abs(sub));
            ans = max(ans, num);
        }
        return ans;
    }
};