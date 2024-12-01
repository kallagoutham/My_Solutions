//Using DFS

class Solution {
public:
    bool hasPath(int source,int destination,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        if(source==destination){return true;}
        visited[source]=true;
        bool res=false;
        for(auto i=adj[source].begin();i!=adj[source].end();i++){
            if(!visited[*i]){
                res=res||hasPath(*i,destination,adj,visited);
            }
        }
        return res;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        for(auto i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        return hasPath(source,destination,adj,visited);
    }
};

// Using BFS

class Solution {
public:
    bool hasPath(int source,int destination,unordered_map<int,vector<int>>& adj,vector<bool>& visited){
        if(source==destination){return true;}
        queue<int> q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            visited[q.front()]=true;
            for(int i:adj[q.front()]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    if(i==destination){return true;}
                }
            }
            q.pop();
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        for(auto i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        return hasPath(source,destination,adj,visited);
    }
};
