using p = pair<int,int>;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<p>> adjList(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adjList[i].push_back({j,wt});
                adjList[j].push_back({i,wt});
            }
        }
        vector<bool> visited(n,false);
        // min-heap ({Wt,node})
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        int res = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!visited[node]){
                visited[node] = true;
                res += wt;
                for(auto neighbor : adjList[node]){
                    pq.push({neighbor.second,neighbor.first});
                }
            }
        }
        return res;
    }
};
