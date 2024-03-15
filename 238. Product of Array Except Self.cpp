class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;
        bool zero = false;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                product*=nums[i];
            }
            if(nums[i]==0){
                zero = true;
                s.insert(i);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(zero){
                    nums[i]=0;
                    continue;
                }   
                nums[i]=product/nums[i];
            }else{
                if(s.size()>1){nums[i]=0;}
                else{nums[i]=product;}
            }
        }
        return nums;
    }
};
