class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=nums[0],mini=nums[0];
        set<int> st;
        for(int i:nums){
            maxi=max(i,maxi);
            mini=min(i,mini);
            st.insert(i);
        }
        vector<int> res;
        for(int i=mini;i<=maxi;i++){
            if(!st.count(i)){
                res.push_back(i);
            }
        }
        return res;
    }
};
