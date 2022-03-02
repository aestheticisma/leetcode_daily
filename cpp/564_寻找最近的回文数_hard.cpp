class Solution {
public:
    string nearestPalindromic(string n) {
        long long len = n.size();
        vector<long long> candidates = {
            (long long) pow(10, len-1) - 1,
            (long long) pow(10, len) + 1
        };
        long long selfPrefix = stol(n.substr(0, (len+1)/2));
        for (int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}) {
            string prefix = to_string(i);
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            candidates.push_back(stol(candidate));
        }

        long long selfNumber = stol(n), ans = -1;
        for (auto candidate : candidates) {
            if (candidate != selfNumber)
                if (ans == -1 || abs(candidate - selfNumber) < abs(ans - selfNumber) || 
                abs(candidate - selfNumber) < abs(ans - selfNumber) && candidate < ans)
                    ans = candidate;
        }
        return to_string(ans);
    }
};