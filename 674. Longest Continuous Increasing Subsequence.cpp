class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1])
                count++;
            else {
                ans = max(ans, count);
                count = 1;
            }
        }

        ans = max(ans, count);

        return ans;
    }
};
