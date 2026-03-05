class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int c=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==1){
                    for(int k=0;k<n;k++){
                        if(mat[i][k]==1 && k!=j){
                            goto l;
                        }
                    }
                    for(int k=0;k<m;k++){
                        if(mat[k][j]==1 && k!=i){
                            goto l;
                        }
                    }
                    c++;
                }
            }
            l:;
        }
        return c;
    }
};
