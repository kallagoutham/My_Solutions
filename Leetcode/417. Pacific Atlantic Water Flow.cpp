class Solution {
public:
    int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> res;
    void dfs(int r,int c,vector<vector<bool>>& reachable,vector<vector<int>>& heights,int rows,int cols){
        reachable[r][c]=true;
        for(auto& dir:d){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr>=0 && nr<rows && nc>=0 && nc<cols && !reachable[nr][nc] && heights[nr][nc] >=heights[r][c]){
                dfs(nr,nc,reachable,heights,rows,cols);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()){
            return {};
        }
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(i,0,pacific,heights,m,n);
            dfs(i,n-1,atlantic,heights,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,pacific,heights,m,n);
            dfs(m-1,i,atlantic,heights,m,n);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
