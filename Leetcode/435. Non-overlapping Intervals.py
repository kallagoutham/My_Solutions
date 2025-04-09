class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:(x[1],x[0]))
        n=len(intervals)
        cnt=1
        lastEndTime=intervals[0][1]
        for i in range(1,n):
            if intervals[i][0]>=lastEndTime:
                cnt+=1
                lastEndTime=intervals[i][1]
        return n-cnt
        
