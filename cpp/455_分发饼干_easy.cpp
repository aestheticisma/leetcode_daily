class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0, j=0;
        int num_g = g.size();
        int num_s = s.size();
        while(i<num_g && j<num_s)
            if(s[j]>=g[i]){
                i++;
                j++;
            }
            else
                j++;
        return i;
    }
};