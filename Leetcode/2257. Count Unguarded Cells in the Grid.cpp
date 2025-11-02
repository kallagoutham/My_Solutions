class Solution {
public:
    void traverse(vector<vector<int>>& room,int r,int c,int m,int n){
        for(int i=c+1;i<n;i++){
            if(room[r][i]==1 || room[r][i]==2){break;}
            room[r][i]=3;
        }
        for(int i=c-1;i>=0;i--){
            if(room[r][i]==1 || room[r][i]==2){break;}
            room[r][i]=3;
        }
        for(int i=r-1;i>=0;i--){
            if(room[i][c]==1 || room[i][c]==2){break;}
            room[i][c]=3;
        }
        for(int i=r+1;i<m;i++){
            if(room[i][c]==1 || room[i][c]==2){break;}
            room[i][c]=3;
        }
        return;
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> room(m,vector<int>(n,0));
        for(vector<int> guard:guards){
            room[guard[0]][guard[1]]=1;
        }
        for(vector<int> wall:walls){
            room[wall[0]][wall[1]]=2;
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(room[i][j]==1){
                    traverse(room,i,j,m,n);
                }
            }
        }
        int res=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(room[i][j]==0){
                    res++;
                }
            }
        }
        return res;

    }
    
};
