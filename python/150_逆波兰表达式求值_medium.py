class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        if not tokens:
            return 0
        f = {
            '+': add,
            '-': sub,
            '*': mul,
            '/': lambda x, y : int(x/y)
        }
        data = list()
        for token in tokens:
            try:
                num = int(token)
            except:
                x = data.pop()
                y = data.pop()
                num = f[token](y, x)
            finally:
                data.append(num)
        return data[0]

