class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        if(threshold==0){
            if(n>1) return -1;
            return 0;
        }
        int miw=INT_MAX,maw=INT_MIN;
        for(vector<int> edge:edges){
            miw=min(miw,edge[2]);
            maw=max(maw,edge[2]);
        }
        int res=-1;
        int l=miw,h=maw;
        while(l<=h){
            int m=(l+h)/2;
            vector<vector<int>> redges(n);
            for(auto& edge:edges){
                int u=edge[0],v=edge[1],w=edge[2];
                if(w<=m){
                    redges[v].push_back(u);
                }
            }
            queue<int> q;
            q.push(0);
            vector<bool> visited(n,false);
            visited[0]=true;
            int vc=1;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(int nxt:redges[curr]){
                        if(!visited[nxt]){
                        visited[nxt]=true;
                        vc++;
                        q.push(nxt);
                    }
                }
            }
            bool cra =(vc==n);
            if(cra){
                res=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return res;
    }
};©leetcode
