class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        isSeen = dict()
        n, exAns = len(answers), 0
        for an in answers:
            if an == 0:
                continue
            elif an not in isSeen:
                isSeen[an] = an
                exAns += an
            else:
                if isSeen[an] > 0:
                    isSeen[an] -= 1
                    exAns -= 1
                else:
                    isSeen[an] = an
                    exAns += an
        return n + exAns