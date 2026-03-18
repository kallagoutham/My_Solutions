#define p pair<int,int>

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<p> maxHeap;
        priority_queue<p, vector<p>, greater<p>> minHeap;

        int j = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});
            minHeap.push({nums[i], i});

            if (!maxHeap.empty() && !minHeap.empty() &&
                   maxHeap.top().first - minHeap.top().first > limit) {
                j++;

                while (!maxHeap.empty() && maxHeap.top().second < j) {
                    maxHeap.pop();
                }
                while (!minHeap.empty() && minHeap.top().second < j) {
                    minHeap.pop();
                }
            }

            res = max(res, i - j + 1);
        }

        return res;
    }
};
