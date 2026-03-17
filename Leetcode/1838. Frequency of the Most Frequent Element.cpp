class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,res=0;
        long current = 0;
        int n=nums.size();
        for(int j=0;j<n;j++){
            long target = nums[j];
            current += target;
            // here we can change it to if as we dont care about smaller window sizes right.
            while((j-i+1)*target - current > k){
                current -= nums[i];
                i++;
            }
            res = max(res,j-i+1);
        }
        return res;
    }
};
