class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int t1 = 0,t2 = 0;
        for (int num : nums) {
            if (num > t1) {
                t2 = t1;
                t1 = num;
            } else {
                t2 = max(t2, num);
            }
        }
        
        return (t1 - 1) * (t2 - 1);
    }
};
