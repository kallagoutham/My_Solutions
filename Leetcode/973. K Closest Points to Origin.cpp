#define pi pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        for(vector<int> point:points){
            pq.push(make_pair(point[0]*point[0] + point[1]*point[1],make_pair(point[0], point[1])));            
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            pi t = pq.top();
            res.push_back({t.second.first,t.second.second});
            pq.pop();
        }
        return res;
    }
};
