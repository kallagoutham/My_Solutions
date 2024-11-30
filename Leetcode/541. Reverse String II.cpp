class Solution {
public:
    string reverseStr(string s, int k) {
        string res;
        int n=s.size();
        for(int i=0;i<n;){
            string temp="";
            int tmp=k;
            while(tmp>0 && i<n){
                temp.push_back(s[i]);
                tmp--;
                i++;
            }
            for(int j=temp.size()-1;j>=0;--j){
                res.push_back(temp[j]);
            }
            tmp=k;
            while(tmp>0 && i<n){
                res.push_back(s[i]);
                tmp--;
                i++;
            }
        }
        return res;
    }
};
