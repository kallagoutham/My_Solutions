class Solution {
public:
    int atMostOddNumbers(vector<int> nums,int k){
        int res = 0, n = nums.size(), count = 0, i = 0;
        for(int j=0;j<n;j++){
        count += ((nums[j] & 1) == 1) ? 1 : 0;
        while(count > k){
                count -= ((nums[i++] & 1) == 1) ? 1 : 0;
            }
            res += (j-i+1);
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostOddNumbers(nums,k) - atMostOddNumbers(nums,k-1);
    }
};
