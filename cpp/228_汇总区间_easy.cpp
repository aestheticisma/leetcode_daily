class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int N = nums.size();
        if(!N)
            return {};
        int i=0;
        vector<string> res;
        while(i<N){
            int start = nums[i];
            int end = start;
            while(i+1<N && nums[i+1]==end+1){
                i++;
                end++;
            }
            if(start == end)
                res.push_back(to_string(start));
            else{
                string tmp = to_string(start);
                tmp.append("->");
                tmp.append(to_string(end));
                res.push_back(tmp);
            }
            i++;
        }
        return res;
    }
};