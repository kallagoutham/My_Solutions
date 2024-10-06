class Solution {
public:
    int computeAverage(vector<vector<int>>& img, int r,int c,int row,int cols){
        int left=r-1,right=r+1,top=c-1,bottom=c+1;
        int count=0;
        int sum=0;
        for(int i=left;i<=right;i++){
            for(int j=top;j<=bottom;j++){
                if((i>=0 && i<row) && (j>=0 &&j<cols)){
                    sum+=img[i][j];
                    count++;
                }
            }
        }
        return sum/count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r=img.size(),c=img[0].size();
        vector<vector<int>> res(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=computeAverage(img,i,j,r,c);
            }
        }
        return res;
    }
};
