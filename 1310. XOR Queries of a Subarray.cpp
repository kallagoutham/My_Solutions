class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> x;
        int prefixXor=0;
        for(int i:arr){
           prefixXor^=i;
            x.push_back(prefixXor);
        }
        vector<int> res;
        for(vector<int> i:queries){
           int s=i[0],e=i[1];
            if(s==0){res.push_back(x[e]);continue;}
            res.push_back(x[e]^x[s-1]);
        }
        return res;
    }
};
