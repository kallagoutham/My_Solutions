using p = pair<int,int>;
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        // lets build the adjList here
        vector<vector<p>> adjList(V);
        for(vector<int> edge:edges){
            adjList[edge[0]].push_back({edge[1],edge[2]});
            adjList[edge[1]].push_back({edge[0],edge[2]});
        }
        int sum = 0;
        // min - heap according to weight 
        // {weigth, node}
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        vector<bool> visited(V,false);
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(!visited[node]){
                visited[node]=true;
                sum += wt;
                for(auto it : adjList[node]){
                    pq.push({it.second,it.first});
                }
            }
        }
        return sum;
    }
};
