class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0;
        int sum = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;
        for (int num : nums) {
            sum += num;
            if (freq.find(sum - goal) != freq.end()) {
                res += freq[sum - goal];
            }
            freq[sum]++;
        }
        return res;
    }
};
