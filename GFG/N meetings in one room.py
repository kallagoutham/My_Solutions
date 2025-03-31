class Solution:
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,start,end):
        meetings=[[x,y] for x,y in zip(start,end)]
        meetings.sort(key=lambda x:x[1])
        noOfMeetingsHeld=0
        freeAt=-1
        for i in meetings:
            if i[0]>freeAt:
                noOfMeetingsHeld+=1
                freeAt=i[1]
        return noOfMeetingsHeld
