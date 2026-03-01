class Solution {
public:
    int minPartitions(string n) {
        int res=INT_MIN;
        for(char c:n){
            res=max(c-'0',res);
        }
        return res;
    }
};
