class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = set()
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        node = Trie()
        m, n = len(board), len(board[0])
        for word in words:
            node.insert(word)
        def dfs(x, y, node):
            ch = board[x][y]
            i = ord(ch) - ord('a')
            if node.children[i] == None:
                return False
            node = node.children[i]
            if len(node.word) > 0:
                res.add(node.word)
            board[x][y] = '#'
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if nx >=0 and nx < m and ny >=0 and ny < n:
                    if board[nx][ny] != '#':
                        dfs(nx, ny, node)
            board[x][y] = ch
            return True
        for i in range(m):
            for j in range(n):
                dfs(i, j, node)
        return list(res)
class Trie:
    def __init__(self):
        self.children = [None]*26
        self.word = ""
    def insert(self, word):
        node = self
        for ch in word:
            i = ord(ch) - ord('a')
            if node.children[i] == None:
                node.children[i] = Trie()
            node = node.children[i]
        node.word = word

