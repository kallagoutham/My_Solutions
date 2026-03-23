class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        int res = 1;
        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            res = max(res, left[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] <= nums[i + 1]) {
                res = max(res, left[i - 1] + 1 + right[i + 1]);
            } else {
                res = max(res, max(left[i - 1] + 1, right[i + 1] + 1));
            }
        }

        res = max(res, right[1] + 1);
        res = max(res, left[n - 2] + 1);

        return min(res, n);
    }
};
