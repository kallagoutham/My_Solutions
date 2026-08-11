class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> m(nums.begin(), nums.end());
        int res = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                res += nums[i];
            } else {
                break;
            }
        }

        while (m.count(res)) {
            res += 1;
        }

        return res;
    }
};
