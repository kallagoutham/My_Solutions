# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q=deque()
        q.append(root)
        res=1
        mx=root.val
        l=1
        while q:
            s=len(q)
            a=0
            while s>0:
                t=q[0]
                q.popleft()
                if t.right:
                    q.append(t.right)
                if t.left:
                    q.append(t.left)
                a+=t.val
                s-=1
            if a>mx:
                mx=a
                res=l
            l+=1
        return res
