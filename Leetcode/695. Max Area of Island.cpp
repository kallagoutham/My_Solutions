class Solution {
public:
    int area=0;
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int r,int c,int m,int n){
        return r>=0 && r<m && c>=0 && c<n; 
    }
    void bfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int row,int col){
        visited[row][col]=true;
        area++;
        for(int i=0;i<4;i++){
            int nr=row+dir[i][0];
            int nc=col+dir[i][1];
            if(isValid(nr,nc,grid.size(),grid[0].size()) && !visited[nr][nc] && grid[nr][nc]==1){
                bfs(grid,visited,nr,nc);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int maxArea=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    visited[i][j]=true;
                    continue;
                }
                if(!visited[i][j] && grid[i][j]==1){
                    area=0;
                    bfs(grid,visited,i,j);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};
