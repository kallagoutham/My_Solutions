class Solution:
    #using bfs i.e., Kahn's Algorithm to solve 
    def findOrder(self, n: int, p: List[List[int]]) -> List[int]:
        d=[0]*n
        adj=[[] for _ in range(n)]
        print(adj)
        for i in p:
            adj[i[1]].append(i[0])
            d[i[0]]+=1
        q = deque()
        for i in range(n):
            if d[i]==0:
                q.append(i)
        l=[]
        while q:
            t=q[0]
            q.popleft()
            l.append(t)
            for i in adj[t]:
                d[i]-=1
                if d[i]==0:
                    q.append(i)
        for i in d:
            if i!=0:
                return []
        return l
        
