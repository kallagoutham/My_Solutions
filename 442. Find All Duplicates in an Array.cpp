class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        set<int> s;
        for(int i:nums){
            if(s.find(i)!=s.end()){
                res.push_back(i);
            }else{
                s.insert(i);
            }
        }
        return res;
    }
};
