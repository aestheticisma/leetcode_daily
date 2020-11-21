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


# 法二：自底向上 先将链表分为n份 之后进行两两合并

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        # 两个有序链表合并函数
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
        # 如果链表为空 返回
        if not head:
            return head
        length = 0
        node = head
        # 计算链表长度
        while node:
            node = node.next
            length += 1
        dummyHead, subLength = ListNode(0), 1
        dummyHead.next = head
        # 当subLength大于等于链表总长度时停止
        while(subLength<length):
            pre, current = dummyHead, dummyHead.next
            # 循环两两合并
            while current:
                # 存储第一组链表首部
                head1 = current
                # 将current指向第一组链表尾部
                for i in range(1, subLength):
                    if current.next:
                        current = current.next
                    else: break
                # 存储第二组链表首部
                head2 = current.next
                # 断开第一组链表
                current.next = None
                current = head2
                # 将current指向第二组链表尾部(如果第二组链表存在的话)
                for i in range(1, subLength):
                    if current and current.next:
                        current = current.next
                    else:
                        break
                if current:
                    third = current.next
                    current.next = None
                    current = third
                # 移动pre至下两个将要合并的位置
                pre.next = merge(head1, head2)
                while pre.next:
                    pre = pre.next
            # subLength变为原来的两倍
            subLength <<= 1
        return dummyHead.next