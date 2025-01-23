"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head==None:
            return None
        th=Node(head.val)
        m={}
        t=head
        t=t.next
        m[head]=th
        m[None]=None
        p=th
        while t:
            p.next=Node(t.val)
            p=p.next
            m[t]=p
            t=t.next
        t=head
        p=th
        while t:
            p.random=m[t.random]
            t=t.next
            p=p.next
        return th


        
