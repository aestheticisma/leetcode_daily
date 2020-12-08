class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        length = len(S)
        ans = list()

        def isSucceed(index, sumN, pre):
            if index == length:
                return len(ans)>=3
            current = 0
            for i in range(index, length):
                if i>index and S[index] == '0':
                    break
                current = current*10 + ord(S[i]) - ord('0')
                if current > 2**31-1:
                    break
                if len(ans)>=2:
                    if current > sumN:
                        break
                    elif current < sumN:
                        continue
                ans.append(current)
                if (isSucceed(i+1, pre+current, current)):
                    return True
                ans.pop()
            return False

        isSucceed(0, 0, 0)
        return ans