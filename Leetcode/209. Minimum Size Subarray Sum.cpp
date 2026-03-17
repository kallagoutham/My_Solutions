class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int currentSum = 0;
        int j = 0;
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            currentSum += nums[i];

            while (currentSum >= target) {
                res = min(res, i - j + 1);
                currentSum -= nums[j];
                j++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
