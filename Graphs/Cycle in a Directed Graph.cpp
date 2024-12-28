//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>& visited,vector<int>& currentPath,vector<vector<int>>& adj,int node){
        visited[node]=1;
        currentPath[node]=1;
        for(int nbr:adj[node]){
            if(!visited[nbr]){
                bool res=dfs(visited,currentPath,adj,nbr);
                if(res==true){return true;}
            }else{
                if(currentPath[nbr]){
                    return true;
                }
            }
        }
        currentPath[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> visited(V,0);
        vector<int> currentPath(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool res = dfs(visited,currentPath,adj,i);
                if(res==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
