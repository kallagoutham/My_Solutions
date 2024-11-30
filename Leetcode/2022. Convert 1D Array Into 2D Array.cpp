class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if(m*n != original.size()){return res;}
        int t=0;
        vector<int> temp;
        for(int i:original){
            if(t!=n){
                temp.push_back(i);
                t++;
            }else{
                t=1;
                res.push_back(temp);
                temp.clear();
                temp.push_back(i);
            }
        }
        res.push_back(temp);
        return res;
    }
};
