class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int nums[100] = {0};
        int res = 0;
        for(auto dom : dominoes){
            int x = dom[0], y = dom[1];
            int id = x <= y ? 10*x+y : 10*y+x;
            res += nums[id];
            nums[id]++;
        }
        return res;
    }
};