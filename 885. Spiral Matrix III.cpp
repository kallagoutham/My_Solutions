class Solution {
public:
    bool validPoint(int i,int j,int m,int n){
        return i>=0 && i<=m-1 && j>=0 && j<=n-1;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int step=1,dir=1,i=0;
        while(i<(rows*cols)){
            int temp = step;
            if(dir==1){
                while(temp--){
                    if(validPoint(rStart,cStart,rows,cols)){
                        vector<int> t={rStart,cStart};
                        res.push_back(t);
                        i++;
                    }
                    cStart++;
                }
                temp=step;
                while(temp--){
                    if(validPoint(rStart,cStart,rows,cols)){
                        vector<int> t={rStart,cStart};
                        res.push_back(t);
                        i++;
                    }
                    rStart++;
                }
                dir=-1;
            }else{
                while(temp--){
                    if(validPoint(rStart,cStart,rows,cols)){
                        vector<int> t={rStart,cStart};
                        res.push_back(t);
                        i++;
                    }
                    cStart--;
                }
                temp=step;
                while(temp--){
                    if(validPoint(rStart,cStart,rows,cols)){
                        vector<int> t={rStart,cStart};
                        res.push_back(t);
                        i++;
                    }
                    rStart--;
                }
                dir=1;
            }
            step++;
        }
        return res;
    }
};
