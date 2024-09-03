class Solution {
public:
    int getLucky(string s, int k) {
        int t=1;
        int sum=0;
        for(char c:s){
            int temp=(c-'a'+1);
            while(temp>0){
                sum+=(temp%10);
                temp/=10;
            }
        }
        while(t!=k){
            t++;
            int temp=sum;
            sum=0;
            while(temp>0){
                sum+=temp%10;
                temp/=10;
            }
        }
        return sum;
    }
};
