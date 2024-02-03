class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         int row = grid.size(), col = grid[0].size();
        int ans=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    // if there is only one island
                    ans+=4;
                    // check for upward and left side if both satisfies then ans-=4 
                    // if any one satisfies ans-=2.
                    if(i>0 && grid[i-1][j]==1) ans-=2;
                    if(j>0 && grid[i][j-1]==1) ans-=2;
                }
            }
       }
       return ans; 
    }
};
