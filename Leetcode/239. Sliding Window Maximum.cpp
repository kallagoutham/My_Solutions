class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n=nums.size(),i;
        vector<int> res; 
        for(i=0;i<k;i++){
            pq.push(make_pair(nums[i],i));
        }
        res.push_back(pq.top().first);
        int j=0;
        while(i<n){
            pq.push({nums[i],i});
            while((pq.top().first == nums[j] && pq.top().second == j) || 
                    (pq.top().second < j)){
                pq.pop();
            }
            i++;
            j++;
            res.push_back(pq.top().first);
        }
        return res;
    }
};
