class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0];
        bool res = false;
        for (int v : nums1) {
            mini = min(v,mini);
            if (v & 1) {
                res = true;
            }
        }
        if (mini & 1) {
            return true;
        }
        return !res;
    }
};
