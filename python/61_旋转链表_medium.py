# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head
        dummyHead = ListNode(0, head)
        cur = dummyHead
        num = 0
        while cur.next:
            num += 1
            cur = cur.next
        if not k % num:
            return dummyHead.next
        k %= num
        i = 0
        cur.next = dummyHead.next
        cur = dummyHead
        while cur.next and i < num-k:
            i += 1
            cur = cur.next
        res = ListNode(0, cur.next)
        cur.next = None
        return res.next