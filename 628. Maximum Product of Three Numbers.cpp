/* Using sorting */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return max(nums[n-3]*nums[n-1]*nums[n-2],nums[0]*nums[1]*nums[n-1]);
    }
};
/* Using Arrays */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      int largest[] = {INT_MIN, INT_MIN, INT_MIN};
        int smallest[] = {0,0};
        for (const auto& v : nums) {
            if (v > largest[0]) {
                if (v > largest[1]) {
                    largest[0] = largest[1];
                    if (v > largest[2]) {
                        largest[1] = largest[2];
                        largest[2] = v;
                    } 
                    else largest[1] = v;
                } 
                else largest[0] = v;
            } 
            if (v < smallest[0]) {
                if (v < smallest[1]) {
                    smallest[0] = smallest[1];
                    smallest[1] = v;
                } 
                else smallest[0] = v;
            }
        }
        return max(smallest[0]*smallest[1]*largest[2], largest[0]*largest[1]*largest[2]);
    }
};
