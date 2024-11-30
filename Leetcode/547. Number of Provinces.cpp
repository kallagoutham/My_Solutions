class Solution {
public:
    int res=0;
    void DFS(int src,vector<bool>& visited,vector<vector<int>>& isConnected){
        visited[src]=true;
        for(int i=0;i<isConnected[src].size();i++){
            if(isConnected[src][i]==1 && !visited[i]){
                visited[i]=true;
                DFS(i,visited,isConnected);
            }
        }
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                DFS(i,visited,isConnected);
            }
        }
        return res;
    }
};
