/*Using single loop */
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oc=0,zc=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){oc++;}
            else{zc++;}
        }
        s="";
        while(oc>1){
            s.push_back('1');
            oc--;
        }
        while(zc>0){
            s.push_back('0');
            zc--;
        }
        s.push_back('1');
        return s;
    }
};

/* Using sorting technique */
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(),s.end(),greater<char>());
        int n=s.size()-1;
        if(s[n]=='0'){
            for(int i=n;i>=0;i--){
                if(s[i]=='1'){
                    s[i]='0';
                    s[n]='1';
                    break;
                }
            }
        }
        return s;
    }
};
