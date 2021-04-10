class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) return false;
        int a[3] = {2, 3, 5};
        for (auto num : a) 
            while (n % num == 0)
                n /= num;
        return n == 1 ? true : false;
    }
};