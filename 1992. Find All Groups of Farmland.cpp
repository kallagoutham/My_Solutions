class Solution {
public:
    void dfs(int rows,int columns,int i,int j,vector<int>& ans,vector<vector<int>>& land,vector<vector<bool>>& visited){
        visited[i][j]=true;
        if(i==rows-1 && j==columns-1){
            ans.push_back(i);
            ans.push_back(j);
        }else if(i+1<=rows-1 && j+1<=columns-1 && land[i+1][j]==0 && land[i][j+1]==0){
            ans.push_back(i);
            ans.push_back(j);
        }else if(i==rows-1 && land[i][j+1]==0){
            ans.push_back(i);
            ans.push_back(j);
        }else if(j==columns-1 && land[i+1][j]==0){
            ans.push_back(i);
            ans.push_back(j);
        }
        
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        for(int p=0;p<4;++p){
            int rr=i+dr[p];
            int cc=j+dc[p];
            if(rr>=0 && rr<rows && cc>=0 && cc<columns && land[rr][cc]==1 && !visited[rr][cc]){
                dfs(rows,columns,rr,cc,ans,land,visited);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows=land.size(),columns=0;
        if(rows>0){
            columns=land[0].size();
        }
        vector<vector<int>> res;
        vector<vector<bool>> visited(rows,vector<bool>(columns,false));
        for(int i=0;i<rows;++i){
            for(int j=0;j<columns;++j){
                vector<int> ans;
                if(land[i][j]==1 && !visited[i][j]){
                    ans.push_back(i);
                    ans.push_back(j);
                    dfs(rows,columns,i,j,ans,land,visited);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};
