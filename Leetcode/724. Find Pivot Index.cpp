class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sum;
        int n=nums.size();
        int current_sum=0;
        for(int i=0;i<n;i++){
            current_sum+=nums[i];
            sum.push_back(current_sum);
        }
        if(sum[n-1]==sum[0]){
            return 0;
        }
        for(int i=1;i<n;i++){
            if(sum[i-1]==(sum[n-1]-sum[i]))
                return i;
        }
        return -1;
    }
};
