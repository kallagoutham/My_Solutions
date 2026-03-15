class Solution {
public:
    bool isValidSquare(pair<int,int>& source,pair<int,int>& step,int m,int n){
        int p1 = source.first + step.first;
        int p2 = source.second + step.second;
        return (0<=p1 && p1<m && 0<=p2 && p2<n);
    }
    bool isValidPathForKnight(vector<vector<int>>& grid,vector<pair<int,int>>& steps,pair<int,int>& source,int start, int end,int m,int n){
        if(start == end){
            return true;
        }
        for(pair<int,int> step:steps){
            if(isValidSquare(source,step,m,n)){
                int t1=source.first + step.first;
                int t2=source.second + step.second;
                if(grid[t1][t2] == (start+1)){
                    source = {t1,t2};
                    return isValidPathForKnight(grid,steps,source,start+1,end,m,n);
                }
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,int>> steps= {{-2,-1},{-2,1},{-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1}};
        if(grid[0][0]!=0){return false;}
        pair<int,int> source={0,0};
        return isValidPathForKnight(grid,steps,source,0,(m*n)-1,m,n);
    }
};
