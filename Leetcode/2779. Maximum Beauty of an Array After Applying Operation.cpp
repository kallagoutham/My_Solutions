class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res=INT_MIN,n=nums.size();
        int window_size=0,l=0,r=0;
        sort(nums.begin(),nums.end());
        while(l<=r){
            while(r<n && (nums[r]-nums[l])<=2*k){
                r++;
                window_size++;
            }
            res=max(res,window_size);
            if(r==n) break;
            while(l<r && (nums[r]-nums[l])>2*k){
                l++;
                window_size--;
            }
        }
        return res;
    }
};