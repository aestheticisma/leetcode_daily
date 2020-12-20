class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int left = cost[0];
        int right = cost[1];
        for(int i=2; i<cost.size(); i++){
            int tmp = min(left, right);
            left = right;
            right = tmp + cost[i];
        }
        return min(left, right);
    }
};