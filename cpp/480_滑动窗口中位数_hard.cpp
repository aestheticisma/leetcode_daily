class Solution {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int> > big;
    unordered_map<int, int> mp;
    double get(int k){
        return k%2 ? small.top() : ((long long)small.top() + big.top())*0.5;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for(int i=0; i<k; i++) small.push(nums[i]);
        for(int i=0; i<k/2; i++) {big.push(small.top()); small.pop();}
        vector<double> ans{get(k)};
        for(int i=k; i<nums.size(); i++){
            int left = nums[i-k];
            mp[left]++;
            int balance = 0;
            if (!small.empty() && left <= small.top()) balance--;
            else balance++;
            if (!big.empty() && nums[i] <= small.top()) {balance++;small.push(nums[i]);}
            else {balance--;big.push(nums[i]);}
            if (balance>0) {big.push(small.top()); small.pop();};
            if (balance<0) {small.push(big.top()); big.pop();}
            while(!small.empty() && mp[small.top()] > 0){
                mp[small.top()]--;
                small.pop();
            }
            while(!big.empty() && mp[big.top()] > 0){
                mp[big.top()]--;
                big.pop();
            }
            ans.push_back(get(k));
        }
        return ans;
    }
};