class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        stack5, stack10 = [], []
        while bills:
            if bills[0]==5:
                stack5.append(bills[0])
                bills.pop(0)
            elif bills[0]==10:
                if stack5:
                    stack10.append(bills[0])
                    stack5.pop()
                    bills.pop(0)
                else:
                    return False
            else:
                if stack10 and stack5:
                    stack10.pop()
                    stack5.pop()
                    bills.pop(0)
                elif len(stack5)>2:
                    stack5 = stack5[:-3]
                    bills.pop(0)
                else:
                    return False
        return True