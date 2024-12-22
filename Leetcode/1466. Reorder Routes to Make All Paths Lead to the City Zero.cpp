class Solution {
public:
    void dfs(int source,vector<vector<int>>& forward,vector<vector<int>>& backward,int& ans,vector<int>& visited){
        visited[source]=1;
        for(int i:forward[source]){
            if(!visited[i]){
                ans++;
                dfs(i,forward,backward,ans,visited);
            }
        }
        for(int i:backward[source]){
            if(!visited[i]){
                dfs(i,forward,backward,ans,visited);
            }
        }
        return;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n),backward(n);
        vector<int> visited(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        int ans=0;
        dfs(0,forward,backward,ans,visited);
        return ans;
    }
};
