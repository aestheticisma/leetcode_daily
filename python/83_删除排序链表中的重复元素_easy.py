# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
        dummyHead = ListNode(0, head)
        cur = dummyHead
        while cur.next and cur.next.next:
            if cur.next.val == cur.next.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return dummyHead.next