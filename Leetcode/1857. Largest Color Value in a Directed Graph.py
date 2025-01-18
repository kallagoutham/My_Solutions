class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n=len(colors)
        d=[0]*n
        f=[[0]*26 for _ in range(n)]
        adj=[[] for _ in range(n)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            d[edge[1]]+=1
        dq = deque()
        for i in range(n):
            if d[i]==0:
                dq.append(i)
        res=-1
        while dq:
            t=dq[0]
            dq.popleft()
            f[t][ord(colors[t])-ord('a')]+=1
            res=max(res,f[t][ord(colors[t])-ord('a')])
            for nbr in adj[t]:
                d[nbr]-=1
                f[nbr]=[max(x,y) for x,y in zip(f[nbr],f[t])]
                if d[nbr]==0:
                    dq.append(nbr)
        for i in d:
            if i!=0:
                return -1
        return res
