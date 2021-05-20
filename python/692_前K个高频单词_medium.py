class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        cnt = collections.defaultdict(int)
        for word in words:
            cnt[word] += 1
        res = list()
        for word, val in cnt.items():
            res.append(word)
        def compare(a, b):
            if cnt[a] > cnt[b]:
                return -1
            elif cnt[a] == cnt[b]:
                if a < b:
                    return -1
                else:
                    return 1
            else:
                return 1
        res = sorted(res, key = functools.cmp_to_key(compare))
        return res[:k]
