class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = list()
        for i in range(numRows):
            ret = list()
            for j in range(0, i+1):
                if j==0 or j==i:
                    ret.append(1)
                else:
                    ret.append(ans[i-1][j-1]+ans[i-1][j])
            ans.append(ret)
        return ans