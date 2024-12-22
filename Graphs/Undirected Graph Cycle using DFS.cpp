#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node,vector<int>& visited,vector<vector<int>>& adj,int parent){
        visited[node]=1;
        for(int i:adj[node]){
            if(!visited[i]){
                bool ans = dfs(i,visited,adj,node);
                if(ans){return true;}
            }
            else{
                if(visited[i]==1 && parent!=i){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
       vector<int> visited(adj.size());
       for(int i=0;i<adj.size();i++){
           if(!visited[i]){
               bool ans=dfs(i,visited,adj,-1);
               if(ans==true){
                   return true;
               }
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
