# 二分法 时间复杂度O(logn) 空间复杂度O(1)
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 2:
            return True
        left, right = 2, num//2
        while(left <= right):
            ans = (left+right)//2
            ans_2 = ans*ans
            if ans_2 == num:
                return True
            elif ans_2 > num:
                right = ans - 1
            else:
                left = ans + 1
        return False


# 牛顿迭代法 时间复杂度O(logn) 空间复杂度O(1)
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 2:
            return True
        ans = num // 2
        while(ans*ans > num):
            ans = (ans + num//ans) // 2
        return ans*ans == num