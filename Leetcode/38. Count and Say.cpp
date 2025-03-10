class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1){
            return "1";
        }
        string s="1";
        string res="";
        while(n-->1){
            int n=s.length();
            res="";
            int c=1;
            char prev=s[0];
            for(int i=1;i<n;i++){
                if(s[i]==prev){
                    c++;
                }
                else{
                    res+='0'+c;
                    res+=prev;
                    prev=s[i];
                    c=1;
                }
            }
            res+='0'+c;
            res+=prev;
            s=res;
        }
        return res;
    }
};
