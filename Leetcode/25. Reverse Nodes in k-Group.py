from collections import deque
# from typing import Optional

# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 1 or not head:
            return head

        st = deque()  
        g = 0
        th = head  
        pgt = None  #previous group tail
        temp_head = head

        while temp_head:
            t = k
            while t > 0 and temp_head:
                st.append(temp_head)
                temp_head = temp_head.next
                t -= 1

            if t == 0:  
                gh = st.pop() #group head
                p = gh

                while st:
                    p.next = st.pop()
                    p = p.next

                if g == 0:  # First group, update head
                    th = gh
                else:
                    pgt.next = gh  # Connect previous group's tail to new group head

                pgt = p  # Update previous group's tail
                p.next = temp_head  # Connect to next segment
                g += 1

        return th
