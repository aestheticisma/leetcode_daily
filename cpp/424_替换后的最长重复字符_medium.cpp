class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxCount = 0;
        int left = 0;
        int right = 0;
        vector<int> num(26, 0);
        int ans = 0;
        while (right < n) {
            num[s[right]-'A']++;
            maxCount = max(maxCount, num[s[right]-'A']);
            right++;
            if (right-left > maxCount+k) {
                num[s[left]-'A']--;
                left++;
            }
            ans = max(ans, right-left);
        }
        return ans;
    }
};