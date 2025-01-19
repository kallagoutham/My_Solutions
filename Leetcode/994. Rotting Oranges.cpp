class Solution {
public:
    bool isValidPoint(int i,int j,int m,int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        queue<pair<int,int>> q;
        int cnt=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        if(cnt==0){return 0;}
        int s=q.size();
        int res=0;
        while(!q.empty()){
            while(s--){
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int ii=p.first+dx[i];
                    int jj=p.second+dy[i];
                    if(isValidPoint(ii,jj,m,n)){
                        if(grid[ii][jj]==1){
                            grid[ii][jj]=2;
                            q.push(make_pair(ii,jj));
                        }
                    }
                }
            }
            s=q.size();
            res++;
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    return -1;
        return res-1;
    }
};
