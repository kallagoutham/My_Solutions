class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        for(int n:nums){
            res.push_back(a*n*n + b*n + c);
        }
        sort(res.begin(),res.end());
        return res;
    }

};
