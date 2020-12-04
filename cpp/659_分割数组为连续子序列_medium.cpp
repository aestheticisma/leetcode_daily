class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int, int> cnt, ent;
        for(int el : nums)
            cnt[el]++;
        for(int el : nums)
            if(!cnt[el])
                continue;
            else if(ent[el-1]){
                ent[el-1]--;
                ent[el]++;
                cnt[el]--;
            }
            else if(cnt[el+1] && cnt[el+2]){
                cnt[el]--;
                cnt[el+1]--;
                cnt[el+2]--;
                ent[el+2]++;
            }
            else return false;
        return true;
    }
};