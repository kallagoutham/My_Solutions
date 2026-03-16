class Solution {
public:
    bool canChange(string start, string target) {
        int n=target.size();
        int i=0,j=0;
        while(i<n && j<n){
            while(start[i]=='_' && i<n){
                i++;
            }
            while(target[j]=='_' && j<n){
                j++;
            }
            if(start[i]!=target[j]){
                return false;
            }else{
                if(start[i]=='L' && (i<j)){
                    return false;
                }else if(start[i]=='R' && (i>j)){
                    return false;
                }
            }
            i++;
            j++;
        }
        if(i==n){
            while(j<n){
                if(target[j]!='_'){
                    return false;
                }
                j++;
            }
        }else{
             while(i<n){
                if(start[i]!='_'){
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};  
