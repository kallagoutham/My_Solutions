class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        int t=k;
        while(st.count(t)){
            t+=k;
        }
        return t;
    }
};
