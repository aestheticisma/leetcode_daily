class Solution:
    def simplifyPath(self, path: str) -> str:
        if not path:
            return path
        stk = list()
        strList = [x for x in path.split('/') if x]
        while strList:
            if strList[0] == '.':
                strList.pop(0)
                continue
            elif stk and strList[0] == '..':
                stk.pop()
            else:
                if (strList[0] != '..'):
                    stk.append(strList[0])
            strList.pop(0)
        return '/' + "/".join(stk)