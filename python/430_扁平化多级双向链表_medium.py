"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def child2brother(parent):
            child, nextNode = parent.child, parent.next
            parent.next, child.prev = child, parent
            parent.child = None
            while child:
                if child.child:
                    child2brother(child)
                else:
                    if child.next:
                        child = child.next
                    else:
                        break
            child.next = nextNode
            if nextNode:
                nextNode.prev = child
        
        ptr = head
        while ptr:
            if ptr.child:
                child2brother(ptr)
            else:
                ptr = ptr.next
        return head




