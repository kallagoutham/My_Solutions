class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int c=1;
        char ch=s[0];
        res.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(ch==s[i]){
                c++;
                if(c<=2){
                    res.push_back(s[i]);
                }
            }else{
                c=1;
                ch=s[i];
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
