class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        def gain(p,t):
            return ((p+1)/(t+1))-(p/t)
        heap=[]
        for i in range(len(classes)):
            heappush(heap, (-gain(classes[i][0],classes[i][1]),classes[i][0],classes[i][1]))
        for i in range(extraStudents):
            g, p, t = heappop(heap)
            p, t = p + 1, t + 1
            heappush(heap, (-gain(p, t), p, t))
        totalRatio=0.0
        while heap:
            g, p, t = heappop(heap)
            totalRatio += p/t
        return totalRatio/len(classes)

        
