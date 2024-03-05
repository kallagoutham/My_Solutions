class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                char t=s[i];
                while(i<n && s[i]==t){
                    i++;
                }
                while(j>=0 && s[j]==t){
                    j--;
                }   
            }else{
                return j-i+1;
            }
        }
        if(j-i+1 > 0){return j-i+1;}
        return 0;
    }
};
