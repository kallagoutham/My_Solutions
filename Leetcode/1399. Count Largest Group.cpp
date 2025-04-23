class Solution {
public:
    int sumOfDigits(int num){
        int s=0;
        while(num){
            s+=num%10;
            num/=10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> m;
        int maxFrequency = INT_MIN;
        for(int i=1;i<=n;i++){
            int t=sumOfDigits(i);
            maxFrequency = max(++m[t],maxFrequency);
        }
        int res=0;
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second == maxFrequency){
                res++;
            }
        }
        return res;
    }
};
