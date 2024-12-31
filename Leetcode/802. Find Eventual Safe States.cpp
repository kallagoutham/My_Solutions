class Solution {
public:
    bool dfs(vector<int>& visited,vector<int>& currentPath,vector<vector<int>>& graph,int node){
        visited[node]=1;
        currentPath[node]=1;
        for(int nbr:graph[node]){
            if(!visited[nbr]){
                bool ans = dfs(visited,currentPath,graph,nbr);
                if(ans==true){
                    return true;
                }
            }else{
                if(currentPath[nbr]==1){
                    return true;
                }
            }
        }
        currentPath[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> currentPath(n,0);
        vector<int> res;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited,currentPath,graph,i);
            }
        }
        for(int i=0;i<n;i++){if(currentPath[i]==0){res.push_back(i);}}
        return res;
    }
};
