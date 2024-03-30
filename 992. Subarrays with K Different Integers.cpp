class Solution {
public:
    //atmost function finds the total number of sub arrays with atmost k different integers
    int atmost(vector<int>&nums,int k,int n){
        int start=0,end=0,res=0;
        unordered_map<int,int> m;
        while(end<n){
            m[nums[end]]++;
            while(m.size()>k){
                auto it=m.find(nums[start]);
                it->second--;
                start++;
                if(it->second==0){m.erase(it);}
            }
            res+=(end-start+1);
            end++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atmost(nums,k,n)-atmost(nums,k-1,n); // exactly 3 means atmost(3)-atmost(2)
    }
};
