class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mi= arrays[0][0],res=0,ma=arrays[0].back();
        for (int i=1;i<arrays.size();i++) {
            res=max(res, abs(arrays[i].back() - mi));
            res=max(res, abs(ma - arrays[i][0]));
            mi=min(mi, arrays[i][0]);
            ma=max(ma, arrays[i].back());
        }
        return res;
    }
};
