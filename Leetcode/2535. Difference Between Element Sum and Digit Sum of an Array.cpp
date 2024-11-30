class Solution {
public:
    int digitSum(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int es=0;
        int ds=0;
        for(int i=0;i<nums.size();i++){
            es+=nums[i];
            ds+=digitSum(nums[i]);
        }
        return abs(es-ds);
    }
};
