class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int sum=0,minimum=INT_MAX;
        int idx=-1;
        // if(s.find('1')==string::npos || s.find('0')==string::npos){return n-1;}
        for(int i=0;i<n;i++){
            if(s[i]=='1'){sum++;}
            else{sum--;}
            if(sum<minimum){
                minimum=sum;
                idx=i;
            }
        }
        if(idx==n-1){idx-=1;}
        sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'&&i<=idx){
                sum++;
            }
            if(s[i]=='1'&&i>idx){
                sum++;
            }
        }
        return sum;
    }
};
