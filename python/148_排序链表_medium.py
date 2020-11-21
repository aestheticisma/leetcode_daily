# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# 插入排序算法时间复杂度O(n^2) 超出时间限制
# 对于链表来说，最方便使用归并排序算法 时间复杂度O(nlogn)
# 法一：自顶向下
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        def divideList(head, tail):
            if not head:
                return head
            if head.next == tail:
                head.next = None
                return head
            slow, fast = head, head
            while fast != tail:
                slow = slow.next
                fast = fast.next
                if fast != tail:
                    fast = fast.next
            mid = slow
            return merge(divideList(head, mid), divideList(mid, tail))
        def merge(head1, head2):
            dummyHead = ListNode(0)
            temp, temp1, temp2 = dummyHead, head1, head2
            while temp1 and temp2:
                if temp1.val <= temp2.val:
                    temp.next = temp1
                    temp1 = temp1.next
                else:
                    temp.next = temp2
                    temp2 = temp2.next
                temp = temp.next
            if temp1:
                temp.next = temp1
            elif temp2:
                temp.next = temp2
            return dummyHead.next
        return divideList(head, None)