class Solution {
public:
    int diameter(unordered_map<int,vector<int>>& adj,int n){
        vector<int> visited(n,0);
        queue<int> q;
        visited[0]=1;
        q.push(0);
        int s;
        int t;
        while(!q.empty()){
            s=q.size();
            for(int i=0;i<s;i++){
                t=q.front();
                q.pop();
                visited[t]=true;
                for(int j:adj[t]){
                    if(!visited[j]){
                        q.push(j);
                    }
                }
            }
        }
        //start from the last node again
        fill(visited.begin(), visited.end(), 0);
        q.push(t);
        t=0;
        int diameter=0;
        while(!q.empty()){
            s=q.size();
            for(int i=0;i<s;i++){
                t=q.front();
                q.pop();
                visited[t]=true;
                for(int j:adj[t]){
                    if(!visited[j]){
                        q.push(j);
                    }
                }
            }
            diameter++;
        }
        return diameter-1;
    }
    int findDiameter(vector<vector<int>>& edges){
        if(edges.size()==0){return 0;}
        unordered_map<int,vector<int>> adj;
        set<int> nodes;
        for(vector<int> edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        return diameter(adj,nodes.size());
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1=findDiameter(edges1);
        int d2=findDiameter(edges2);
        int res=max(1+ (d1+1)/2 + (d2+1)/2, max(d1,d2));
        return res;
    }
};
