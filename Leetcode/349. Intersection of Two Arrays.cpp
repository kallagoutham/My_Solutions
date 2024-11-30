class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> res;
        for(int i:nums1){
            m[i]++;
        }
        for(int i : nums2){
            if(m.find(i)!=m.end()){
                res.push_back(i);
                m.erase(i);
            }
        }
        return res;
    }
};
