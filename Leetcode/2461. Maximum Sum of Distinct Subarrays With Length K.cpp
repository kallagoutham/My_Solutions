#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0, res = 0;
        int n = nums.size();
        
        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
            sum += nums[i];
        }
        
        if (freq.size() == k) {
            res = max(res, sum);
        }
        
        for (int i = k; i < n; ++i) {
            freq[nums[i]]++;
            sum += nums[i] - nums[i - k];
            
            if (--freq[nums[i - k]] == 0) {
                freq.erase(nums[i - k]);
            }
            
            if (freq.size() == k) {
                res = max(res, sum);
            }
        }
        
        return res;
    }
};
