// 调用stl中优先队列实现

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>> maxHeap;
        for(int i=0; i<k; i++)
            maxHeap.emplace(nums[i], i);
        ans.push_back(maxHeap.top().first);
        for(int i=k; i<N; i++){
            maxHeap.emplace(nums[i], i);
            while(maxHeap.top().second <= i-k)
                maxHeap.pop();
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};