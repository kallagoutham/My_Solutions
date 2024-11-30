class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(m.find(i->first - 1)!=m.end()){
                res=max(res,i->second + m[i->first - 1]);
            }
            if(m.find(i->first + 1)!=m.end()){
                res=max(res,i->second + m[i->first + 1]);
            }
        }
        return res;
    }
};
