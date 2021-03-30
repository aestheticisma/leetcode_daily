# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        def merge2Lists(a, b):
            if not a or not b:
                return a if a else b
            head = ListNode()
            tail = head
            aPtr, bPtr = a, b
            while aPtr and bPtr:
                if aPtr.val < bPtr.val:
                    tail.next = aPtr
                    aPtr = aPtr.next
                elif aPtr.val >= bPtr.val:
                    tail.next = bPtr
                    bPtr = bPtr.next
                tail = tail.next
            tail.next = aPtr if aPtr else bPtr
            return head.next
        
        ans = None
        for node in lists:
            ans = merge2Lists(ans, node)
        return ans