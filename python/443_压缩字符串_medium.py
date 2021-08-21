class Solution:
    def compress(self, chars: List[str]) -> int:
        def reverse(left, right):
            while left < right:
                chars[left], chars[right] = chars[right], chars[left]
                left += 1
                right -= 1

        n = len(chars)
        write, left = 0, 0
        for read in range(n):
            if read == n-1 or chars[read] != chars[read+1]:
                chars[write] = chars[read]
                write += 1
                length = read - left + 1
                if length > 1:
                    tmp = write
                    while length > 0:
                        chars[write] = str(length % 10)
                        write += 1
                        length //= 10
                    reverse(tmp, write-1)
                left = read + 1
        return write
