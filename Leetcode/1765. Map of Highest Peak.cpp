class Solution {
public:

    bool isValid(int i,int j,int m,int n){
        return i>=0 && j>=0 && j<n && i<m;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};
        vector<vector<int>> res(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push(make_pair(i,j));
                    res[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for (int k=0;k<4;k++) {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if (isValid(ni, nj, m, n) && res[ni][nj] == -1) {
                    res[ni][nj] = res[i][j] + 1; 
                    q.push({ni, nj});
                }
            }
        }
        
        return res;
    }
};
