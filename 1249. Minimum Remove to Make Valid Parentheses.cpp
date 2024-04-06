class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count=0;
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }else if(s[i]==')'){
                if(count>0){
                    count--;
                }else{
                    s[i]='.';
                }
            }
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                count++;
            }else if(s[i]=='('){
                if(count>0){
                    count--;
                }else{
                    s[i]='.';
                }
            }
        }
        for(char i:s){
            if(i!='.'){
                res.push_back(i);
            }
        }
        return res;
    }
};
