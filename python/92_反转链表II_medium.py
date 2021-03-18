# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummyHead = ListNode(next = head)
        p = head
        stk = list()
        begin = dummyHead
        pos = 1
        while p:
            if pos < left:
                begin = p
            elif pos >= left and pos <= right:
                stk.append(p)
            else:
                break
            p = p.next
            pos += 1
        while stk:
            begin.next = stk.pop()
            begin = begin.next
        if begin:
            begin.next = p
        return dummyHead.next