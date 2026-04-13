class Solution {
  public:
  
    void dfs(int node,vector<bool>& vis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]=true;
        for(int i:adj[node]){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> vis(V,false);
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
