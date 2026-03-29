class Solution {
public:
    void BFS(int node,vector<bool>& visited,vector<vector<int>>& adjList){
        if(visited[node]){return;}
        visited[node]=true;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int n = q.front();
                q.pop();
                for(int neighbour : adjList[n]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n==1){return 1;}
        vector<vector<int>> adjList(n);
        vector<bool> visited(n,false);
        int res = 0;
        for(auto edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                BFS(i,visited,adjList);
            }
        }
        return res;
    }
};
