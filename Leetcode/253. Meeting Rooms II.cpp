class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = INT_MIN;
        int cnt=0,n=intervals.size();
        priority_queue<int,vector<int>,greater<int>> startHeap, endHeap;
        for(vector<int> interval : intervals){
            startHeap.push(interval[0]);
            endHeap.push(interval[1]);
        }
        while(!startHeap.empty()){
            if(startHeap.top() < endHeap.top()){
                cnt++;
                startHeap.pop();
            }else{
                cnt--;
                endHeap.pop();
            }
            res = max(res,cnt);
        }
        return res;
    }
};
