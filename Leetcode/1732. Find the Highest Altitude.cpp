class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, tmp = 0;
        for(int i:gain){
            tmp += i;
            res = max(res,tmp);
        }
        return res;
    }
};
