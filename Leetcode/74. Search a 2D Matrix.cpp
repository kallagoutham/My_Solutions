class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0){return false;}
        int n=matrix[0].size();
        int left = 0, right = m*n -1;
        int pivotIndx,pivotElement;
        while(left<=right){
            pivotIndx = (left + right)/2;
            pivotElement = matrix[pivotIndx/n][pivotIndx%n];
            if(target==pivotElement){
                return true;
            }else{
                if(target<pivotElement){
                    right=pivotIndx-1;
                }else{
                    left=pivotIndx+1;
                }
            }
        }
        return false;
    }
};
