// 二分法 时间复杂度O(logn) 空间复杂度O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2)
            return true;
        int left=2, right=num/2;
        while(left<=right)
        {
            long ans = (left+right)/2;
            long ans_2 = ans*ans;
            if(ans_2==num)
                return true;
            else if(ans_2>num)
                right = ans-1;
            else
                left = ans+1;
        }
        return false;
    }
};

// 牛顿迭代法 时间复杂度O(logn) 空间复杂度O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<2)
            return true;
        long ans = num/2;
        long ans_2 = ans*ans;
        while(ans_2>num)
        {
            ans = (ans + num/ans)/2;
            ans_2 = ans*ans;
        }
        return ans_2==num;
    }
};