#define pi pair<long long,pair<long long,long long>>
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        long long res = 0;
        for(int workerTime : workerTimes){
            pq.push(make_pair(workerTime,make_pair(workerTime,1)));
        }
        while(mountainHeight--){
            pi t = pq.top();
            pq.pop();
            res = max(res,t.first);
            pq.push(make_pair(t.first + (t.second.first*(t.second.second+1)),make_pair(t.second.first,t.second.second+1)));
        }
        return res;
    }
};
