class Solution {
public:
    int dp[205][205];
    int helper(vector<vector<int>>& arr,int r,int c){
        int n=arr.size(),m=0;
        if(n>0){
            m=arr[0].size();
        }
        if(r>=n){
            return 0;
        }
        int ans=INT_MAX;
        if(dp[r][c]!=-1){return dp[r][c];}
        for(int i=0;i<m;++i){
            if(i!=c){ans=min(ans,helper(arr,r+1,i));}
        }
        return dp[r][c]=ans+arr[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=0;
        if(n>0){
            m=grid[0].size();            
        }
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){ans=min(ans,helper(grid,0,i));}
        return ans;
    }
};
