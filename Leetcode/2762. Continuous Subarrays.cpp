class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int l = 0, r = 0;
        int n = nums.size();
        deque<int> maxDeque, minDeque;

        while (r < n) {
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(r);

            while (!maxDeque.empty() && !minDeque.empty() && 
                   nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                l++;
                if (!maxDeque.empty() && maxDeque.front() < l) {
                    maxDeque.pop_front();
                }
                if (!minDeque.empty() && minDeque.front() < l) {
                    minDeque.pop_front();
                }
            }
            res += (r - l + 1);
            r++;
        }

        return res;
    }
};
