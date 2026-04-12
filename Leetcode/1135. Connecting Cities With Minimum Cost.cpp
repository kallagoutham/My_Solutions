using p = pair<int,int>;
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // kind of Minimum Spanning Tree problem 
        // MST - n nodes, n-1 edges, all nodes are reachable from each other.
        vector<vector<p>> adjList(n+1);
        int res = 0;
        for(vector<int> connection : connections){
            adjList[connection[0]].push_back({connection[1],connection[2]});
            adjList[connection[1]].push_back({connection[0],connection[2]});
        }
        vector<bool> visited(n+1,false);
        // min-heap ( {wt,node})
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,1});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(!visited[node]){
                visited[node]=true;
                res += wt;
                for(auto neighbor : adjList[node]){
                    pq.push({neighbor.second,neighbor.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                return -1;
            }
        }
        return res;
    }
};
