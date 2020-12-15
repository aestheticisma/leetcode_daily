class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        if N < 10:
            return N
        list_N = []
        while N:
            num = N % 10
            N //= 10
            list_N.append(num)        
        list_N = list_N[::-1]
        for i in range(1, len(list_N)):
            if list_N[i]<list_N[i-1]:
                j = i-1
                while(j>0 and list_N[j]==list_N[j-1]):
                    j -= 1
                list_N[j], j = list_N[j]-1, j+1
                while(j<len(list_N)):
                    # return 1
                    list_N[j] = 9
                    j += 1
        return int(''.join([str(ch) for ch in list_N]))