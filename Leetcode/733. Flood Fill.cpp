class Solution {
public:
    // for cpp code i will be using dfs 
    int r,c;
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,-1,0,1};

    void dfs(int i,int j,int col,int oc,vector<vector<int>>& image){
        //base condition checks
        if(i<0 || j<0 || i>=r || j>=c || image[i][j]!=oc)   return;
        image[i][j]=col;
        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],col,oc,image);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r=image.size(),c=image[0].size();
        int oc=image[sr][sc];
        if(oc==color)   return image;
        dfs(sr,sc,color,oc,image);
        return image;
    }
};
