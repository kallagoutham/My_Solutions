class Solution {
public:
    //Using DFS for now cpp implementation 
    //maintaining visited, deque, current path and if cycle is present then returning empty.
    bool dfs(int node,vector<int>& visited,vector<int>& cp,vector<vector<int>>& adj,deque<int>& d){
        visited[node]=1;
        cp[node]=1;
        for(int nbr:adj[node]){
            if(!visited[nbr]){
                if(dfs(nbr,visited,cp,adj,d)){
                    return true;
                }
            }else{
                if(cp[nbr]==1){
                    return true;
                }
            }
        }
        cp[node]=0;
        d.push_front(node);
        return false;

    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> visited(n,0),cp(n,0);
        vector<vector<int>> adj(n);
        deque<int> d;
        for(auto& i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;++i){
            if(!visited[i]){
                if(dfs(i,visited,cp,adj,d)){
                    return {};
                }
            }
        }
        vector<int> res;
        while(!d.empty()){
            res.push_back(d.front());
            d.pop_front();
        }
        return res;
    }
};
