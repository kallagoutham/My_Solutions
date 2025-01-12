class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        int m=grid.size(),n=grid[0].size();
        bool skip=false;
        for(int i=0;i<m;i++){
            if(i%2==0){
                for(int j=0;j<n;j++){
                    if(!skip){
                        res.push_back(grid[i][j]);
                    }
                    skip=!skip;
                }
            }else{
                for(int j=n-1;j>=0;j--){
                    if(!skip){
                        res.push_back(grid[i][j]);
                    }
                    skip=!skip;
                }
            }
        }
        return res;
    }
};
