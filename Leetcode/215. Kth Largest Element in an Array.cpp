/* Brute force approach NlogN */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
};

/* Using the Priority Queue and the Time Complexity NlogK */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<k;i++){minHeap.push(nums[i]);}
        for(int i=k;i<nums.size();i++){
            if(minHeap.top()<nums[i]){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
