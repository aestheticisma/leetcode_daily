class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        email2index = collections.defaultdict(list)
        for i in range(len(accounts)):
            for email in accounts[i][1:]:
                email2index[email].append(i)
        id_visit = set()
        email_visit = set()
        def dfs(i):
            if i in id_visit:
                return
            id_visit.add(i)
            for email in accounts[i][1:]:
                if email in email_visit:
                    continue
                email_visit.add(email)
                ans[-1].append(email)
                for _i in email2index[email]:
                    dfs(_i)
        ans = []
        for i in range(len(accounts)):
            if i not in id_visit:
                ans.append(accounts[i][:1])
                dfs(i)
        for i in range(len(ans)):
            ans[i] = ans[i][:1]+sorted(ans[i][1:])
        return ans