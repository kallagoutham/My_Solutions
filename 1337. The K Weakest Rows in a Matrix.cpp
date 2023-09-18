class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> map;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    c++;
                }
            }
            map[c].push_back(i);
        }
        vector<int> res;
        for(auto i=map.begin();i!=map.end();i++){
            sort((i->second).begin(),(i->second).end(),greater<int>());
            while(k>0 && i->second.size()>0){
                int num = i->second.back();
                i->second.pop_back();
                res.push_back(num);
                k--;
            }
            if(k==0){
                return res;
            }
        }
        return res;
    }
};
