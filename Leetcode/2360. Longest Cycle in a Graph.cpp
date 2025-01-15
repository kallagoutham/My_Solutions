class Solution {
public:
    int res=-1;
    void dfs(int len,int node,vector<int>& visited,vector<int>& cp,vector<int>& edges){
        visited[node]=1;
        cp[node]=len+1;
        if(edges[node]!=-1){
            if(!visited[edges[node]]){
                //continue dfs
                dfs(len+1,edges[node],visited,cp,edges);
            }else if(cp[edges[node]]!=0){
                //visited and cycle detected
                res=max(res,cp[node]-cp[edges[node]]+1);
            }
        }
        cp[node]=0; //backtracking again
        return;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> visited(n,0);
        vector<int> cp(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(0,i,visited,cp,edges);
            }
        }
        return res;
    }
};
