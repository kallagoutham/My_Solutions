class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<vector<int>,int> m;
        vector<int> v;
        int res=INT_MIN;
        for(auto& r:matrix){
            if(r[0]){
                v=r;
            }else{
                for(int i:r){
                    v.push_back(i^1);
                }
            }
            res=max(res,++m[v]);
            v.clear();
        }
        return res;
    }
};
