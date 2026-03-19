class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return true;
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        for(vector<int> interval:intervals){
            minHeap.push(interval);
        } 
        int maxStart = minHeap.top()[0], maxEnd = minHeap.top()[1];
        minHeap.pop();
        while(!minHeap.empty()){
            if(minHeap.top()[0]> maxStart && minHeap.top()[0]>=maxEnd && minHeap.top()[1]>maxEnd){
                maxStart = minHeap.top()[0];
                maxEnd = minHeap.top()[1];
                minHeap.pop();
                continue;
            }
            return false;
        }
        return true;
    }
};
