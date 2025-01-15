class Solution:
    def __init__(self):
        self.res=-1
    def longestCycle(self, edges: List[int]) -> int:
        n=len(edges)
        visited=[0]*n
        cp=[0]*n
        for i in range(n):
            if visited[i]==0:
                self.dfs(0,i,visited,cp,edges)
        return self.res
    def dfs(self,l,node,visited,cp,edges):
        visited[node]=1
        cp[node]=l+1
        nbr = edges[node]
        if nbr!=-1:
            if visited[nbr]!=1:
                self.dfs(l+1,nbr,visited,cp,edges)
            elif cp[nbr]!=0:
                #cycle detected
                self.res=max(self.res,cp[node]-cp[nbr]+1)
        cp[node]=0 #backtrack and going back
        return
