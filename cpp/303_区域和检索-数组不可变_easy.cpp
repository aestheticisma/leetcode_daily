class NumArray {
private:
    vector<int> mm;
public:
    NumArray(vector<int>& nums) {
        mm.push_back(0);
        for (auto num : nums)
            mm.push_back(num+mm.back());
    }
    
    int sumRange(int i, int j) {
        return mm[j+1] - mm[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */