class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int N = s.length();
        if (N < 3)
            return {};
        int i=0;
        vector<vector<int>> ans;
        while (i+2 < N){
            if (s[i] == s[i+1] && s[i+1] == s[i+2]){
                int start = i;
                i += 2;
                while (i+1<N && s[i]==s[i+1])
                    i++;
                int end = i;
                ans.push_back({start, end});
            }
            i++;
        }
        return ans;
    }
};