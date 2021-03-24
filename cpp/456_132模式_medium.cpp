class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int N = nums.size();
        if (N < 3)  return false;
        stack<int> candidate_k;
        candidate_k.push(nums[N-1]);
        int max_k = INT_MIN;
        for(int i=N-2; i>=0; i--) {
            if (nums[i] < max_k)
                return true;
            while (!candidate_k.empty() && nums[i]>candidate_k.top()) {
                max_k = candidate_k.top();
                candidate_k.pop();
            }
            if (nums[i]>max_k)
                candidate_k.push(nums[i]);
        }
        return false;
    }
};