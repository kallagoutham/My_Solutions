class Solution {
public:
    int findNoOfPairsWithDiffK(vector<int>&nums,int mid,int n){
        //returns the number of pairs with the difference less than or equal to mid
        int i=0,ans=0;
        for(int j=1;j<n;j++){
            while(nums[j]-nums[i]>mid){i++;}
            ans+=(j-i);
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        //finding the lowest difference and the highest difference
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int high=nums[n-1]-nums[0],low=INT_MAX;
        //the minimum value is possible if and only if the nums are adjacent
        for(int i=0;i<nums.size()-1;i++){
            low=min(nums[i+1]-nums[i],low);
        }
        while(low<high){
            int mid=(low+high)/2;
            //finds the number of pairs with difference equal or less than mid
            int ans=findNoOfPairsWithDiffK(nums,mid,n);
            if(ans<k){
                //as the maximum number of pairs with that difference would be less than k which will never give us a answer.
                low=mid+1;
            }else{
                //we are trying for the better answer here.
                high=mid;
            }
        }
        return low;
    }
};
