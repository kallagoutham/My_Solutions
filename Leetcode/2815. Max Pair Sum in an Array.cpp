class Solution {
public:
    int maxSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int,vector<int>> m ;
        for(int j=0;j<nums.size();j++){
            m[maxDigit(nums[j])].push_back(nums[j]);
        }
        for(auto i = m.begin();i!=m.end();i++){
            sort(i->second.begin(),i->second.end());
            if (i->second.size() >= 2) {
    res = max(res, (i->second[i->second.size() - 1] + i->second[i->second.size() - 2]));
}
        }
        return res;
    }
    int maxDigit(int num){
        int mx= INT_MIN;
        while(num>0){
            mx = max(mx,num%10);
            num/=10;
        }
        return mx;
    }
};
