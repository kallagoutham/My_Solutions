class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> mnums;
        for (int i = 0; i < n; i++) {
            mnums.push_back({nums[i], i});
        }
        sort(mnums.begin(), mnums.end());
        priority_queue<int, vector<int>, greater<int>> pq;  
        int i = 0, j;
        while (i < n) {
            j = i + 1;
            while (j < n && mnums[j].first - mnums[j - 1].first <= limit) {
                j++;
            }
            for (int l = i; l < j; l++) {
                pq.push(mnums[l].second);
            }
            for (int l = i; l < j; l++) {
                int idx = pq.top(); pq.pop();
                nums[idx] = mnums[l].first;
            }
            i = j;
        }
        return nums;
    }
};
