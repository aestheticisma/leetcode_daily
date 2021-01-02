# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head:
            return head
        dummyHead, tmp = ListNode(0, head), ListNode(0)
        p, pt = dummyHead, tmp
        while p.next:
            if p.next.val < x:
                p = p.next
            else:
                tmp.next = p.next
                p.next = p.next.next
                tmp = tmp.next
                tmp.next = None
        p.next = pt.next
        return dummyHead.next