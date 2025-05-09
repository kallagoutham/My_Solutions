class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) m[nums[i] * nums[j]]++;
        }
        for(auto i : m) ans += ((i.second * (i.second - 1)) / 2) * 8;
        return ans;
    }
};
