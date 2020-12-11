class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        N = len(senate)
        radiant = collections.deque()
        dire = collections.deque()
        for index, ch in enumerate(senate):
            if ch == 'R':
                radiant.append(index)
            else:
                dire.append(index)
        while radiant and dire:
            if radiant[0] < dire[0]:
                radiant.append(radiant[0]+N)
            else:
                dire.append(dire[0]+N)
            radiant.popleft()
            dire.popleft()
        return 'Radiant' if radiant else 'Dire'