class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int n = s.length();
        int num = 0;
        int i = 0;
        while (i < n) {
            while (i<n && s[i] == ' ') i++;
            while (i<n && s[i]>='0' && s[i]<='9') {
                num = num*10 + (s[i] - '0');
                i++;
            }
            switch (preSign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back() *= num;
                    break;
                default:
                    stk.back() /= num;
                    break;
            }
            while (i<n && s[i] == ' ') i++;
            if (i < n) {
                preSign = s[i];
                i++;
            }
            num = 0;
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};