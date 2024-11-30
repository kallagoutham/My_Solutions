class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> res(n,-1);
        for(int i=0;i<n;i++){
            if(res[index[i]]==-1){
                res[index[i]]=nums[i];
            }
            else{
                for(int j=n-1;j>index[i];j--){
                    res[j]=res[j-1];
                }
                res[index[i]]=nums[i];
            }
        }
        return res;
    }
};
