# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        set_G = set(G)
        p = head
        ans = 0
        while p.next:
            if p.val in set_G and p.next.val not in set_G:
                # print(p.val, p.next.val)
                ans += 1
            p = p.next
        if p.val in set_G:
            ans += 1
        return ans