class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        res=[[-1]*len(isWater[0]) for _ in range(len(isWater))]
        q=deque()
        for i in range(len(isWater)):
            for j in range(len(isWater[0])):
                if isWater[i][j]==1:
                    q.append([i,j])
                    res[i][j]=0
        dx=[-1,0,1,0]
        dy=[0,-1,0,1]
        while q:
            i,j=q[0]
            q.popleft()
            for u in range(4):
                nx=i+dx[u]
                ny=j+dy[u]
                if nx>=0 and nx<len(isWater) and ny<len(isWater[0]) and ny>=0 and res[nx][ny]==-1:
                    q.append([nx,ny])
                    res[nx][ny]=res[i][j]+1
        return res

        
