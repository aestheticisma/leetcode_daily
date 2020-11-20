# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        dummyHead = ListNode(0)
        dummyHead.next = head
        lastOrder = head
        current = head.next
        while current:
            if current.val >= lastOrder.val:
                lastOrder = lastOrder.next
            else:
                pre = dummyHead
                while pre.next.val <= current.val:
                    pre = pre.next
                lastOrder.next = current.next
                current.next = pre.next
                pre.next = current
            current = lastOrder.next
        return dummyHead.next