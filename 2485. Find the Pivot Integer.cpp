class Solution {
public:
    int pivotInteger(int n) {
        if(n==1){return 1;}
        int totalSum=0,partialSum=0;
        for(int i=1;i<=n;i++){totalSum+=i;}
        for(int i=n;i>0;i--){
            partialSum+=i;
            if(partialSum==totalSum){return i;}
            totalSum-=i;
        }
        return -1;
    }
};
