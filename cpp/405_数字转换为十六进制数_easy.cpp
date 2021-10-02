class Solution {
public:
    string toHex(int num) {
        if (!num) return "0";
        string ans;
        for (int i=7; i>=0; i--) {
            int var = num >> (4*i) & 0xf;
            if (ans.length()>0 || var > 0) {
                char res = var < 10 ? (char)('0'+var) : (char)('a' + var - 10);
                ans.push_back(res);
            }
        }
        return ans;
    }
};