class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start=0,end=0;
        unordered_map<int,int> m;
        int n=nums.size();
        int res=1;
        while(start<n && end<n){
            if(m.find(nums[end])==m.end()){
                m[nums[end]]++;
                res=max(res,end-start+1);
                end++;
            }else{
                if(m[nums[end]]==k){
                    while(start<=end){
                        if (nums[start] == nums[end]) {
                            m[nums[start]]--;
                            start++;
                            break;
                        } else {
                            m[nums[start]]--;
                            start++;
                        }
                    }
                }else{
                    m[nums[end]]++;
                    res=max(res,end-start+1);
                    end++;
                }
            }
        }
        return res;
    }
};
