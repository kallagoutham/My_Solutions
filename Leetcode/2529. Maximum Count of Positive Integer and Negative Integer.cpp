class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        // Find the last negative index using binary search
        int l = 0, h = n - 1;
        int neg = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] < 0) {
                neg = m;   // Update last negative index
                l = m + 1; // Search in the right half
            } else {
                h = m - 1; // Search in the left half
            }
        }
        
        // Find the first positive index using binary search
        l = 0, h = n - 1;
        int pos = n; // Default to n if no positive number is found
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] > 0) {
                pos = m;   // Update first positive index
                h = m - 1; // Search in the left half
            } else {
                l = m + 1; // Search in the right half
            }
        }
        
        // Calculate counts
        int neg_count = neg + 1;   // Since index is zero-based
        int pos_count = n - pos;   // Remaining elements are positive
        
        return max(neg_count, pos_count);
    }
};
