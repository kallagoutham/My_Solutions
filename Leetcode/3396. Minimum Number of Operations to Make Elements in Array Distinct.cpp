class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(),i;
        unordered_set<int> freq;
        bool duplicate=false;
        for( i=n-1;i>=0;i--){
            if(freq.count(nums[i])==0){
                freq.insert(nums[i]);
            }else{
                duplicate=true;
                break;
            }
        }
        if(i==0 && duplicate==false){
            return 0;
        }
        return (i+3)/3;
        
    }
};
