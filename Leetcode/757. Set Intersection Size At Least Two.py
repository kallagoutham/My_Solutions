class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:(x[1],-x[0]))
        secondLast,Last,ans=-1,-1,0
        for (a,b) in intervals:
            if a <= secondLast:
                #already 2 are included
                #nothing to do 
                pass
            elif a>secondLast and a<=Last:
                #only one included we have to increase ans by 1
                ans+=1
                secondLast=Last
                Last=b
            else:
                #no interval included
                ans+=2
                secondLast=b-1
                Last=b
        return ans
        
