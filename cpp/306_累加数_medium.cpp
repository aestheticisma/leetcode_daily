class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        if (n < 3) return false;
        for (int secondStart = 1; secondStart < n-1; ++secondStart) {
            if (num[0] == '0' && secondStart > 1) break;
            for (int secondEnd = secondStart; secondEnd < n-1; ++secondEnd) {
                if (num[secondStart] == '0' && secondEnd > secondStart) break;
                if (isValid(num, secondStart, secondEnd))
                    return true;
            }
        }
        return false;
    }
    bool isValid(string &num, int secondStart, int secondEnd) {
        int n = num.length();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd < n-1) {
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = thirdStart + third.length() - 1;
            if (thirdEnd >= n || num.substr(thirdStart, third.length()) != third)
                break;
            if (thirdEnd == n-1) return true;
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }
    string stringAdd(string &num, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        string third;
        int cur = 0, carry = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry) {
            cur = carry;
            if (firstEnd >= firstStart) cur += num[firstEnd--] - '0';
            if (secondEnd >= secondStart) cur += num[secondEnd--] - '0';
            // cur += carry;
            carry = cur / 10;
            cur %= 10;
            third.push_back('0' + cur);
        }
        reverse(third.begin(), third.end());
        return third;
    }
};