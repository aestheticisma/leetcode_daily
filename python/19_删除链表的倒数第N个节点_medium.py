# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# 法1: 栈
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummyHead = ListNode(0, head)
        current = dummyHead
        pos = []
        while(current):
            pos.append(current)
            current = current.next
        for i in range(n):
            pos.pop()
        current = pos[-1]
        current.next = current.next.next
        return dummyHead.next