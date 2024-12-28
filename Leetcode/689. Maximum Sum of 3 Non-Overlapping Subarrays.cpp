class Solution {
public:
    vector<int> ps;
    int mem[200001][3];
    vector<int> max_sum_path;
    int findMaxSum(vector<int>& nums, int pos,int count,int k){
        if(count==3){return 0;}
        if(pos>nums.size()-k){return 0;}
        if(mem[pos][count]!=-1){return mem[pos][count];}
        int exclude = findMaxSum(nums,pos+1,count,k);
        int include = findMaxSum(nums,pos+k,count+1,k) + ps[pos+k]-ps[pos];
        return mem[pos][count] = max(include,exclude);
    }
    
    void findMaxSumPath(vector<int>& nums,int pos,int count,int& k, vector<int>& path){
        if(count==3) return;
        if(pos>nums.size()-k) return;
        int exclude = findMaxSum(nums,pos+1,count,k);
        int include = findMaxSum(nums,pos+k,count+1,k) + ps[pos+k]-ps[pos];
        if(include>=exclude){
            path.push_back(pos);
            findMaxSumPath(nums,pos+k,count+1,k,path);
        }else{
            findMaxSumPath(nums,pos+1,count,k,path);
        }
        return;
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        memset(mem,-1,sizeof(mem));
        ps = vector<int>(n+1,0);
        for(int i=0;i<n;i++){
            ps[i+1]=ps[i]+nums[i];
        }
        // int max_sum = findMaxSum(nums,0,0,k);
        vector<int> res;
        findMaxSumPath(nums,0,0,k,res);
        return res;
    }
};
