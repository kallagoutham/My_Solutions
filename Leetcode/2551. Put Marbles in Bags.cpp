class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) 
            return 0;
        
        int n = weights.size();
        vector<long long> sums;

        for (int i = 0; i < n - 1; i++) {
            sums.push_back(weights[i] + weights[i + 1]);
        }

        sort(sums.begin(), sums.end());

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += sums[i];
            maxSum += sums[sums.size() - 1 - i];
        }

        return maxSum - minSum;
    }
};
