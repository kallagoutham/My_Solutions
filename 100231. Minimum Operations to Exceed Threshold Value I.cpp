class Solution {
public:
    int minOperations(vector<int>& n, int k) {
        int res=0;
        for(int i:n){
            res+=(i<k)?1:0;
        }
        return res;
    }
};
