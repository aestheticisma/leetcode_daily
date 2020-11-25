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

# 法2: 双指针
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummyHead = ListNode(0, head)
        first, second = head, dummyHead
        for i in range(n):
            first = first.next
        while first:
            first = first.next
            second = second.next
        second.next = second.next.next
        return dummyHead.next