class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> reshapedMatrix;
        vector<int> nums;
        vector<int> t;
        int rows = mat.size();
        int cols = rows>0?mat[0].size():0;
        if((rows * cols) == (r * c)){
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    nums.push_back(mat[i][j]);
                }
            }
            int i=0;
            while(i<nums.size()){
                t.clear();
                int j=0;
                while(j<c){
                    t.push_back(nums[i]);
                    i++;
                    j++;
                }
                reshapedMatrix.push_back(t);
            }
            return reshapedMatrix;
        }
        return mat;
    }
};
