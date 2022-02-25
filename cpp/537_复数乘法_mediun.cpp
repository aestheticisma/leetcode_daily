typedef pair<int, int> PII;
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto [r1, i1] = getRI(num1);
        auto [r2, i2] = getRI(num2);
        return to_string(r1*r2 - i1*i2) + "+" + to_string(r1*i2 + i1*r2) + "i";
    }
    PII getRI(string num) {
        int num1 = 0, num2 = 0, i = 0;
        int sign1 = 1, sign2 = 1;
        if (num[0] == '-') {
            sign1 = -1;
            ++i;
        }
        while (i < num.size()) {
            if (num[i] == '+') {
                ++i;
                break;
            }
            else {
                num1 = num1*10 + num[i] - '0';
                ++i;
            }
        }
        if (num[i] == '-') {
            sign2 = -1;
            ++i;
        }
        while (i < num.size()) {
            if (num[i] == 'i') break;
            else {
                num2 = num2 * 10 + num[i] - '0';
                ++i;
            }
        }
        return make_pair(num1*sign1, num2*sign2);
    }
};