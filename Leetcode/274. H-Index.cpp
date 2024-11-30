class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> n(1001,0);
        for(int i:citations){
            n[i]++;
        }
        int sum=0;
        for(int i=1000;i>0;--i){
            if(sum+n[i] >= i){return i;}else{sum+=n[i];}
        }
        return 0;
    }
};
