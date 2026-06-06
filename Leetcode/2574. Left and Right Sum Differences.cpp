class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n),rs(n);
        ls[0] = 0;
        rs[n-1] = 0;
        for(int i=1;i<n;i++){
            ls[i] = ls[i-1] + nums[i-1];
            rs[n-1-i] = rs[n-i] + nums[n-i];
        }
        for(int i=0;i<n;i++){
            // cout << ls[i] << "   "<< rs[i]<<endl;
            ls[i] = abs(ls[i] - rs[i]);
        }
        return ls;
    }
};
