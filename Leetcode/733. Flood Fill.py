class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        # now i will be using bfs
        r,c=len(image),len(image[0])
        oc=image[sr][sc]
        if color==oc:
            return image
        q=deque( [(sr, sc)] )
        while q:
            i,j=q[0]
            q.popleft()
            if i<0 or j<0 or i>=r or j>=c or image[i][j]!=oc:
                continue
            image[i][j]=color
            #4 n3ighbouts
            q.append((i,j+1))
            q.append((i+1,j))
            q.append((i-1,j))
            q.append((i,j-1))
        return image
        
