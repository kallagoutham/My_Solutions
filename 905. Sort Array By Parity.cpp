class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;

        while(i<j){
            while((nums[i]&1)==0 && i<j){i++;}
            while((nums[j]&1)==1 && j>i){j--;}
            if(i<j){
                nums[i]=nums[i]+nums[j];
                nums[j]=nums[i]-nums[j];
                nums[i]=nums[i]-nums[j];
            }
        }
        return nums;
    }
};
