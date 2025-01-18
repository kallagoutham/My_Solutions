class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> d(n,0);
        vector<vector<int>> adj(n),f(n,vector<int>(26,0));
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            d[edge[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(d[i]==0){
                q.push(i);
            }
        }
        int res=INT_MIN;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            // f[t][colors[t]-'a']++;
            res=max(res,++f[t][colors[t]-'a']);
            for(int nbr:adj[t]){
                d[nbr]--;
                if(d[nbr]==0){
                    q.push(nbr);
                }
                for(int i=0;i<26;i++){
                    f[nbr][i]=max(f[nbr][i],f[t][i]);
                }
            }
        }
        //first check whether cycle or not
        for(int i:d){
            if(i!=0)    return -1;
        }
        return res;
    }
};
