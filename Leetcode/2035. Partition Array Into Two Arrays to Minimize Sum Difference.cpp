class Solution {
public:
    int solve(vector<int>& sum1, vector<int>& sum2, int tot) {
        int minDiff = INT_MAX;

        for (int i = 0; i < sum1.size(); i++) {
            int target = tot / 2 - sum1[i];
            int lb = lower_bound(sum2.begin(), sum2.end(), target) - sum2.begin();

            if (lb == sum2.size()) {
                minDiff = min(minDiff, abs(tot - 2 * (sum1[i] + sum2[lb - 1])));
            } 
            else if (lb == 0) {
                minDiff = min(minDiff, abs(tot - 2 * (sum1[i] + sum2[lb])));
            } 
            else {
                minDiff = min({
                    minDiff,
                    abs(tot - 2 * (sum1[i] + sum2[lb - 1])),
                    abs(tot - 2 * (sum1[i] + sum2[lb]))
                });
            }
        }
        return minDiff;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int tot = 0;
        vector<int> nums1, nums2;

        for (int i = 0; i < n; i++) {
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i + n]);
            tot += nums[i] + nums[i + n];
        }

        vector<int> sum1[n + 1], sum2[n + 1];

        for (int mask = 0; mask < (1 << n); ++mask) {
            int tot1 = 0, tot2 = 0, count = 0;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    tot1 += nums1[j];
                    tot2 += nums2[j];
                    count++;
                }
            }

            sum1[count].push_back(tot1);
            sum2[count].push_back(tot2);
        }

        for (int i = 0; i <= n; i++) {
            sort(sum2[i].begin(), sum2[i].end());
        }

        int minDiff = INT_MAX;
        for (int i = 0; i <= n; i++) {
            minDiff = min(minDiff, solve(sum1[i], sum2[n - i], tot));
        }

        return minDiff;
    }
};
