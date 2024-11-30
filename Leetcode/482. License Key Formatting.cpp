class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        transform(s.begin(), s.end(), s.begin(), ::toupper); 
        string res;
        int c=0;
        for(char ch:s){
            if(ch=='-'){
                continue;
            }
            c++;
        }
        if(c%k!=0){c=c%k;}else{c=k;}
        for(char ch:s){
            if(ch=='-'){continue;}
            if(c==0){res.push_back('-');c=k;}
            res.push_back(ch);
            c--;
        }
        return res;
    }
};
