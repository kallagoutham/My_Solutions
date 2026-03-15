class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> temp;
        while(nums.size()!=1){
            int n=nums.size();
            bool mini=true;
            for(int i=0;i<n-1;i+=2){
                mini==true? temp.push_back(min(nums[i],nums[i+1])) : temp.push_back(max(nums[i],nums[i+1]));
                mini = !mini;
            }
            nums=temp;
            temp.clear();
        }
        return nums[0];
    }
};
