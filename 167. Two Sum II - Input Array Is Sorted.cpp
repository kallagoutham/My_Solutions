class Solution {
public:
    int BSR(vector<int>& nums,int k,int l,int h){
        while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid]==k){
            return mid;
        }
        else if(nums[mid]>k){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> r;
        for(int i=0;i<n;i++){
            int idx=BSR(numbers,target-numbers[i],i+1,n-1);
            if(idx>0){
                r.push_back(i+1);
                r.push_back(idx+1);
                return r;
            }
        }
        return r;
    }
};
