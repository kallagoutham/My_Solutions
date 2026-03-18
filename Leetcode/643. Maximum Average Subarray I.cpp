class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int average = 0,n=nums.size(),i;
        for(i=0;i<k;i++){
            average += nums[i];
        }
        double res = (double)average;
        while(i<n){
            average += nums[i];
            average -= nums[i-k];
            res = max(res,(double)average);
            i++;
        }
        return res/k;
    }
};
